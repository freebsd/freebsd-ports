--- src/tui.rs.orig	2025-05-18 18:11:22 UTC
+++ src/tui.rs
@@ -640,6 +640,7 @@ impl Tui {
 
             tree,
             last_modal: None,
+            focused_node: None,
             next_block_id_mixin: 0,
             needs_settling: false,
 
@@ -653,6 +654,9 @@ impl Tui {
         // out where is to do a binary search of commenting out code in main.rs.
         debug_assert!(ctx.tree.current_node.borrow().stack_parent.is_none());
 
+        // End the root node.
+        ctx.block_end();
+
         // Ensure that focus doesn't escape the active modal.
         if let Some(node) = ctx.last_modal
             && !self.is_subtree_focused(&node.borrow())
@@ -684,18 +688,8 @@ impl Tui {
         // Remove any unknown nodes from the focus path.
         // It's important that we do this after the tree has been swapped out,
         // so that pop_focusable_node() has access to the newest version of the tree.
-        let focus_path_changed = self.pop_focusable_node(focus_path_pop_min);
-        needs_settling |= focus_path_changed;
+        needs_settling |= self.pop_focusable_node(focus_path_pop_min);
 
-        // If some elements went away and the focus path changed above, we ignore tab presses.
-        // It may otherwise lead to weird situations where focus moves unexpectedly.
-        if !focus_path_changed
-            && !ctx.input_consumed
-            && let Some(input) = ctx.input_keyboard
-        {
-            needs_settling |= self.move_focus(input);
-        }
-
         // `needs_more_settling()` depends on the current value
         // of `settling_have` and so we increment it first.
         self.settling_have += 1;
@@ -1213,117 +1207,6 @@ impl Tui {
         last_before != last_after
     }
 
-    // TODO: Move this into `block_end()` and run it whenever the block is a `focus_well`.
-    // It makes no sense otherwise that all input handling occurs in the controls, except for this.
-    fn move_focus(&mut self, input: InputKey) -> bool {
-        if !matches!(input, vk::TAB | SHIFT_TAB | vk::UP | vk::DOWN | vk::LEFT | vk::RIGHT) {
-            return false;
-        }
-
-        let focused_id = self.focused_node_path.last().cloned().unwrap_or(0);
-        let Some(focused) = self.prev_node_map.get(focused_id) else {
-            debug_assert!(false); // The caller should've cleaned up the focus path.
-            return false;
-        };
-
-        let mut focused_start = focused;
-        let mut root = focused;
-
-        // Figure out if we're inside a focus void (a container that doesn't
-        // allow tabbing inside), and in that case, toss the focus to it.
-        //
-        // Also, figure out the container within which the focus must be contained.
-        // This way, tab/shift-tab only moves within the same window.
-        // The ROOT_ID node has no parent, and the others have a float attribute.
-        // If the root is the focused node, it should of course not move upward.
-        loop {
-            let root_node = root.borrow();
-            if root_node.attributes.focus_well {
-                break;
-            }
-            if root_node.attributes.focus_void {
-                focused_start = root;
-            }
-            root = match root_node.parent {
-                Some(parent) => parent,
-                None => break,
-            }
-        }
-
-        let forward;
-        let min_depth;
-        match input {
-            SHIFT_TAB | vk::TAB => {
-                forward = input == vk::TAB;
-                min_depth = usize::MAX;
-            }
-            vk::UP | vk::DOWN => {
-                forward = input == vk::DOWN;
-                min_depth = usize::MAX;
-            }
-            vk::LEFT | vk::RIGHT => {
-                // Find the cell within a row within a table that we're in.
-                // To do so we'll use a circular buffer of the last 3 nodes while we travel up.
-                let mut buf = [None; 3];
-                let mut idx = buf.len() - 1;
-                let mut node = focused_start;
-
-                loop {
-                    idx = (idx + 1) % buf.len();
-                    buf[idx] = Some(node);
-                    if let NodeContent::Table(..) = &node.borrow().content {
-                        break;
-                    }
-                    if ptr::eq(node, root) {
-                        return false;
-                    }
-                    node = match node.borrow().parent {
-                        Some(parent) => parent,
-                        None => return false,
-                    }
-                }
-
-                // The current `idx` points to the table.
-                // The last item is the row.
-                // The 2nd to last item is the cell.
-                let Some(row) = buf[(idx + 3 - 1) % buf.len()] else {
-                    return false;
-                };
-                let Some(cell) = buf[(idx + 3 - 2) % buf.len()] else {
-                    return false;
-                };
-
-                root = row;
-                focused_start = cell;
-                forward = input == vk::RIGHT;
-                min_depth = root.borrow().depth;
-            }
-            _ => return false,
-        }
-
-        let mut focused_next = focused_start;
-        Tree::visit_all(root, focused_start, forward, |node| {
-            let n = node.borrow();
-            if ptr::eq(node, root) {
-                VisitControl::Continue
-            } else if n.attributes.focusable && !ptr::eq(node, focused_start) {
-                focused_next = node;
-                VisitControl::Stop
-            } else if n.attributes.focus_void || n.depth >= min_depth {
-                VisitControl::SkipChildren
-            } else {
-                VisitControl::Continue
-            }
-        });
-
-        if ptr::eq(focused_next, focused_start) {
-            false
-        } else {
-            Tui::build_node_path(Some(focused_next), &mut self.focused_node_path);
-            true
-        }
-    }
-
     // Scroll the focused node(s) into view inside scrollviews
     fn scroll_to_focused(&mut self) -> bool {
         let focused_id = self.focused_node_path.last().cloned().unwrap_or(0);
@@ -1375,6 +1258,7 @@ pub struct Context<'a, 'input> {
 
     tree: Tree<'a>,
     last_modal: Option<&'a NodeCell<'a>>,
+    focused_node: Option<&'a NodeCell<'a>>,
     next_block_id_mixin: u64,
     needs_settling: bool,
 
@@ -1484,8 +1368,83 @@ impl<'a> Context<'a, '_> {
     /// Ends the current UI block, returning to its parent container.
     pub fn block_end(&mut self) {
         self.tree.pop_stack();
+        self.block_end_move_focus();
     }
 
+    fn block_end_move_focus(&mut self) {
+        // At this point, it's more like "focus_well?" instead of "focus_well!".
+        let focus_well = self.tree.last_node;
+
+        // Remember the focused node, if any, because once the code below runs,
+        // we need it for the `Tree::visit_all` call.
+        if self.is_focused() {
+            self.focused_node = Some(focus_well);
+        }
+
+        // Filter down to nodes that are focus wells and contain the focus.
+        // They're basically the "tab container".
+        if !focus_well.borrow().attributes.focus_well {
+            return;
+        }
+
+        // The mere fact that there's a `focused_node` indicates that we're the
+        // first `block_end()` call that's a focus well and also contains the focus.
+        let Some(focused) = self.focused_node else {
+            return;
+        };
+
+        // Filter down to Tab/Shift+Tab inputs.
+        if self.input_consumed {
+            return;
+        }
+        let Some(input) = self.input_keyboard else {
+            return;
+        };
+        if !matches!(input, SHIFT_TAB | vk::TAB) {
+            return;
+        }
+
+        let forward = input == vk::TAB;
+        let mut focused_start = focused;
+        let mut focused_next = focused;
+
+        // We may be in a focus void right now (= doesn't want to be tabbed into),
+        // so first we must go up the tree until we're outside of it.
+        loop {
+            if ptr::eq(focused_start, focus_well) {
+                // If we hit the root / focus well, we weren't in a focus void,
+                // and can reset `focused_before` to the current focused node.
+                focused_start = focused;
+                break;
+            }
+
+            focused_start = focused_start.borrow().parent.unwrap();
+            if focused_start.borrow().attributes.focus_void {
+                break;
+            }
+        }
+
+        Tree::visit_all(focus_well, focused_start, forward, |node| {
+            let n = node.borrow();
+            if n.attributes.focusable && !ptr::eq(node, focused_start) {
+                focused_next = node;
+                VisitControl::Stop
+            } else if n.attributes.focus_void {
+                VisitControl::SkipChildren
+            } else {
+                VisitControl::Continue
+            }
+        });
+
+        if ptr::eq(focused_next, focused_start) {
+            return;
+        }
+
+        Tui::build_node_path(Some(focused_next), &mut self.tui.focused_node_path);
+        self.set_input_consumed();
+        self.needs_rerender();
+    }
+
     /// Mixes in an extra value to the next UI block's ID for uniqueness.
     /// Use this when you build a list of items with the same classname.
     pub fn next_block_id_mixin(&mut self, id: u64) {
@@ -1796,6 +1755,8 @@ impl<'a> Context<'a, '_> {
                 debug_assert!(matches!(parent.content, NodeContent::Table(_)));
 
                 self.block_end();
+                self.table_end_row();
+
                 self.next_block_id_mixin(parent.child_count as u64);
             }
         }
@@ -1803,6 +1764,10 @@ impl<'a> Context<'a, '_> {
         self.block_begin("row");
     }
 
+    fn table_end_row(&mut self) {
+        self.table_row_move_focus();
+    }
+
     /// Ends the current table block.
     pub fn table_end(&mut self) {
         let current_node = self.tree.current_node.borrow();
@@ -1811,11 +1776,136 @@ impl<'a> Context<'a, '_> {
         // current_node will refer to the table. Otherwise, it'll refer to the current row.
         if !matches!(current_node.content, NodeContent::Table(_)) {
             self.block_end();
+            self.table_end_row();
         }
 
         self.block_end(); // table
+        self.table_end_move_focus();
     }
 
+    fn table_row_move_focus(&mut self) {
+        // Filter down to table rows that are focused.
+        if !self.contains_focus() {
+            return;
+        }
+
+        // Filter down to left/right inputs.
+        if self.input_consumed {
+            return;
+        }
+        let Some(input) = self.input_keyboard else {
+            return;
+        };
+        if !matches!(input, vk::LEFT | vk::RIGHT) {
+            return;
+        }
+
+        let row = self.tree.last_node;
+        let Some(&focused_cell_id) = self.tui.focused_node_path.get(row.borrow().depth + 1) else {
+            return;
+        };
+
+        let mut prev_next = NodeSiblings { prev: None, next: None };
+        let mut focused = None;
+
+        // Iterate through the cells in the row, looking for the focused cell.
+        // Take note of the previous and next focusable cells around the focused one.
+        for cell in Tree::iterate_siblings(row.borrow().children.first) {
+            let n = cell.borrow();
+            if n.id == focused_cell_id {
+                focused = Some(cell);
+            } else if n.attributes.focusable {
+                if focused.is_none() {
+                    prev_next.prev = Some(cell);
+                } else {
+                    prev_next.next = Some(cell);
+                    break;
+                }
+            }
+        }
+
+        if focused.is_none() {
+            return;
+        }
+
+        let forward = input == vk::RIGHT;
+        let children_idx = if forward { NodeChildren::FIRST } else { NodeChildren::LAST };
+        let siblings_idx = if forward { NodeSiblings::NEXT } else { NodeSiblings::PREV };
+        let Some(focused_next) =
+            prev_next.get(siblings_idx).or_else(|| row.borrow().children.get(children_idx))
+        else {
+            return;
+        };
+
+        Tui::build_node_path(Some(focused_next), &mut self.tui.focused_node_path);
+        self.set_input_consumed();
+        self.needs_rerender();
+    }
+
+    fn table_end_move_focus(&mut self) {
+        // Filter down to table rows that are focused.
+        if !self.contains_focus() {
+            return;
+        }
+
+        // Filter down to up/down inputs.
+        if self.input_consumed {
+            return;
+        }
+        let Some(input) = self.input_keyboard else {
+            return;
+        };
+        if !matches!(input, vk::UP | vk::DOWN) {
+            return;
+        }
+
+        let table = self.tree.last_node;
+        if table.borrow().child_count <= 1 {
+            // If there's just one row, we can't move focus up or down.
+            return;
+        }
+
+        let Some(&focused_row_id) = self.tui.focused_node_path.get(table.borrow().depth + 1) else {
+            return;
+        };
+
+        let mut prev_next = NodeSiblings { prev: None, next: None };
+        let mut focused = None;
+
+        // Iterate through the row in the table, looking for the focused row.
+        // Take note of the previous and next focusable rows around the focused one.
+        for cell in Tree::iterate_siblings(table.borrow().children.first) {
+            let n = cell.borrow();
+            if n.id == focused_row_id {
+                focused = Some(cell);
+            } else if n.attributes.focusable {
+                if focused.is_none() {
+                    prev_next.prev = Some(cell);
+                } else {
+                    prev_next.next = Some(cell);
+                    break;
+                }
+            }
+        }
+
+        if focused.is_none() {
+            return;
+        }
+
+        let forward = input == vk::DOWN;
+        let children_idx = if forward { NodeChildren::FIRST } else { NodeChildren::LAST };
+        let siblings_idx = if forward { NodeSiblings::NEXT } else { NodeSiblings::PREV };
+        let Some(focused_next) =
+            prev_next.get(siblings_idx).or_else(|| table.borrow().children.get(children_idx))
+        else {
+            return;
+        };
+
+        Tui::build_node_path(Some(focused_next), &mut self.tui.focused_node_path);
+        self.set_input_consumed();
+        self.needs_rerender();
+    }
+
     /// Creates a simple text label.
     pub fn label(&mut self, classname: &'static str, text: &str) {
         self.styled_label_begin(classname);
@@ -3312,9 +3402,10 @@ impl<'a> Tree<'a> {
     /// Completes the current node and moves focus to the parent.
     fn pop_stack(&mut self) {
         let current_node = self.current_node.borrow();
-        let stack_parent = current_node.stack_parent.unwrap();
-        self.last_node = self.current_node;
-        self.current_node = stack_parent;
+        if let Some(stack_parent) = current_node.stack_parent {
+            self.last_node = self.current_node;
+            self.current_node = stack_parent;
+        }
     }
 
     fn iterate_siblings(
