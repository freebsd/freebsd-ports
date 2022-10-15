--- lapce-data/src/config.rs.orig	2022-10-14 18:40:17 UTC
+++ lapce-data/src/config.rs
@@ -35,79 +35,79 @@ impl LapceTheme {
 pub struct LapceTheme {}
 
 impl LapceTheme {
-    pub const LAPCE_WARN: &str = "lapce.warn";
-    pub const LAPCE_ERROR: &str = "lapce.error";
-    pub const LAPCE_ACTIVE_TAB: &str = "lapce.active_tab";
-    pub const LAPCE_INACTIVE_TAB: &str = "lapce.inactive_tab";
-    pub const LAPCE_DROPDOWN_SHADOW: &str = "lapce.dropdown_shadow";
-    pub const LAPCE_BORDER: &str = "lapce.border";
-    pub const LAPCE_SCROLL_BAR: &str = "lapce.scroll_bar";
+    pub const LAPCE_WARN: &'static str = "lapce.warn";
+    pub const LAPCE_ERROR: &'static str = "lapce.error";
+    pub const LAPCE_ACTIVE_TAB: &'static str = "lapce.active_tab";
+    pub const LAPCE_INACTIVE_TAB: &'static str = "lapce.inactive_tab";
+    pub const LAPCE_DROPDOWN_SHADOW: &'static str = "lapce.dropdown_shadow";
+    pub const LAPCE_BORDER: &'static str = "lapce.border";
+    pub const LAPCE_SCROLL_BAR: &'static str = "lapce.scroll_bar";
 
-    pub const EDITOR_BACKGROUND: &str = "editor.background";
-    pub const EDITOR_FOREGROUND: &str = "editor.foreground";
-    pub const EDITOR_DIM: &str = "editor.dim";
-    pub const EDITOR_FOCUS: &str = "editor.focus";
-    pub const EDITOR_CARET: &str = "editor.caret";
-    pub const EDITOR_SELECTION: &str = "editor.selection";
-    pub const EDITOR_CURRENT_LINE: &str = "editor.current_line";
-    pub const EDITOR_LINK: &str = "editor.link";
-    pub const EDITOR_VISIBLE_WHITESPACE: &str = "editor.visible_whitespace";
+    pub const EDITOR_BACKGROUND: &'static str = "editor.background";
+    pub const EDITOR_FOREGROUND: &'static str = "editor.foreground";
+    pub const EDITOR_DIM: &'static str = "editor.dim";
+    pub const EDITOR_FOCUS: &'static str = "editor.focus";
+    pub const EDITOR_CARET: &'static str = "editor.caret";
+    pub const EDITOR_SELECTION: &'static str = "editor.selection";
+    pub const EDITOR_CURRENT_LINE: &'static str = "editor.current_line";
+    pub const EDITOR_LINK: &'static str = "editor.link";
+    pub const EDITOR_VISIBLE_WHITESPACE: &'static str = "editor.visible_whitespace";
 
-    pub const INLAY_HINT_FOREGROUND: &str = "inlay_hint.foreground";
-    pub const INLAY_HINT_BACKGROUND: &str = "inlay_hint.background";
+    pub const INLAY_HINT_FOREGROUND: &'static str = "inlay_hint.foreground";
+    pub const INLAY_HINT_BACKGROUND: &'static str = "inlay_hint.background";
 
-    pub const ERROR_LENS_ERROR_FOREGROUND: &str = "error_lens.error.foreground";
-    pub const ERROR_LENS_ERROR_BACKGROUND: &str = "error_lens.error.background";
-    pub const ERROR_LENS_WARNING_FOREGROUND: &str = "error_lens.warning.foreground";
-    pub const ERROR_LENS_WARNING_BACKGROUND: &str = "error_lens.warning.background";
-    pub const ERROR_LENS_OTHER_FOREGROUND: &str = "error_lens.other.foreground";
-    pub const ERROR_LENS_OTHER_BACKGROUND: &str = "error_lens.other.background";
+    pub const ERROR_LENS_ERROR_FOREGROUND: &'static str = "error_lens.error.foreground";
+    pub const ERROR_LENS_ERROR_BACKGROUND: &'static str = "error_lens.error.background";
+    pub const ERROR_LENS_WARNING_FOREGROUND: &'static str = "error_lens.warning.foreground";
+    pub const ERROR_LENS_WARNING_BACKGROUND: &'static str = "error_lens.warning.background";
+    pub const ERROR_LENS_OTHER_FOREGROUND: &'static str = "error_lens.other.foreground";
+    pub const ERROR_LENS_OTHER_BACKGROUND: &'static str = "error_lens.other.background";
 
-    pub const SOURCE_CONTROL_ADDED: &str = "source_control.added";
-    pub const SOURCE_CONTROL_REMOVED: &str = "source_control.removed";
-    pub const SOURCE_CONTROL_MODIFIED: &str = "source_control.modified";
+    pub const SOURCE_CONTROL_ADDED: &'static str = "source_control.added";
+    pub const SOURCE_CONTROL_REMOVED: &'static str = "source_control.removed";
+    pub const SOURCE_CONTROL_MODIFIED: &'static str = "source_control.modified";
 
-    pub const TERMINAL_CURSOR: &str = "terminal.cursor";
-    pub const TERMINAL_BACKGROUND: &str = "terminal.background";
-    pub const TERMINAL_FOREGROUND: &str = "terminal.foreground";
-    pub const TERMINAL_RED: &str = "terminal.red";
-    pub const TERMINAL_BLUE: &str = "terminal.blue";
-    pub const TERMINAL_GREEN: &str = "terminal.green";
-    pub const TERMINAL_YELLOW: &str = "terminal.yellow";
-    pub const TERMINAL_BLACK: &str = "terminal.black";
-    pub const TERMINAL_WHITE: &str = "terminal.white";
-    pub const TERMINAL_CYAN: &str = "terminal.cyan";
-    pub const TERMINAL_MAGENTA: &str = "terminal.magenta";
+    pub const TERMINAL_CURSOR: &'static str = "terminal.cursor";
+    pub const TERMINAL_BACKGROUND: &'static str = "terminal.background";
+    pub const TERMINAL_FOREGROUND: &'static str = "terminal.foreground";
+    pub const TERMINAL_RED: &'static str = "terminal.red";
+    pub const TERMINAL_BLUE: &'static str = "terminal.blue";
+    pub const TERMINAL_GREEN: &'static str = "terminal.green";
+    pub const TERMINAL_YELLOW: &'static str = "terminal.yellow";
+    pub const TERMINAL_BLACK: &'static str = "terminal.black";
+    pub const TERMINAL_WHITE: &'static str = "terminal.white";
+    pub const TERMINAL_CYAN: &'static str = "terminal.cyan";
+    pub const TERMINAL_MAGENTA: &'static str = "terminal.magenta";
 
-    pub const TERMINAL_BRIGHT_RED: &str = "terminal.bright_red";
-    pub const TERMINAL_BRIGHT_BLUE: &str = "terminal.bright_blue";
-    pub const TERMINAL_BRIGHT_GREEN: &str = "terminal.bright_green";
-    pub const TERMINAL_BRIGHT_YELLOW: &str = "terminal.bright_yellow";
-    pub const TERMINAL_BRIGHT_BLACK: &str = "terminal.bright_black";
-    pub const TERMINAL_BRIGHT_WHITE: &str = "terminal.bright_white";
-    pub const TERMINAL_BRIGHT_CYAN: &str = "terminal.bright_cyan";
-    pub const TERMINAL_BRIGHT_MAGENTA: &str = "terminal.bright_magenta";
+    pub const TERMINAL_BRIGHT_RED: &'static str = "terminal.bright_red";
+    pub const TERMINAL_BRIGHT_BLUE: &'static str = "terminal.bright_blue";
+    pub const TERMINAL_BRIGHT_GREEN: &'static str = "terminal.bright_green";
+    pub const TERMINAL_BRIGHT_YELLOW: &'static str = "terminal.bright_yellow";
+    pub const TERMINAL_BRIGHT_BLACK: &'static str = "terminal.bright_black";
+    pub const TERMINAL_BRIGHT_WHITE: &'static str = "terminal.bright_white";
+    pub const TERMINAL_BRIGHT_CYAN: &'static str = "terminal.bright_cyan";
+    pub const TERMINAL_BRIGHT_MAGENTA: &'static str = "terminal.bright_magenta";
 
-    pub const PALETTE_BACKGROUND: &str = "palette.background";
-    pub const PALETTE_CURRENT: &str = "palette.current";
+    pub const PALETTE_BACKGROUND: &'static str = "palette.background";
+    pub const PALETTE_CURRENT: &'static str = "palette.current";
 
-    pub const COMPLETION_BACKGROUND: &str = "completion.background";
-    pub const COMPLETION_CURRENT: &str = "completion.current";
+    pub const COMPLETION_BACKGROUND: &'static str = "completion.background";
+    pub const COMPLETION_CURRENT: &'static str = "completion.current";
 
-    pub const HOVER_BACKGROUND: &str = "hover.background";
+    pub const HOVER_BACKGROUND: &'static str = "hover.background";
 
-    pub const ACTIVITY_BACKGROUND: &str = "activity.background";
-    pub const ACTIVITY_CURRENT: &str = "activity.current";
+    pub const ACTIVITY_BACKGROUND: &'static str = "activity.background";
+    pub const ACTIVITY_CURRENT: &'static str = "activity.current";
 
-    pub const PANEL_BACKGROUND: &str = "panel.background";
-    pub const PANEL_CURRENT: &str = "panel.current";
-    pub const PANEL_HOVERED: &str = "panel.hovered";
+    pub const PANEL_BACKGROUND: &'static str = "panel.background";
+    pub const PANEL_CURRENT: &'static str = "panel.current";
+    pub const PANEL_HOVERED: &'static str = "panel.hovered";
 
-    pub const STATUS_BACKGROUND: &str = "status.background";
-    pub const STATUS_MODAL_NORMAL: &str = "status.modal.normal";
-    pub const STATUS_MODAL_INSERT: &str = "status.modal.insert";
-    pub const STATUS_MODAL_VISUAL: &str = "status.modal.visual";
-    pub const STATUS_MODAL_TERMINAL: &str = "status.modal.terminal";
+    pub const STATUS_BACKGROUND: &'static str = "status.background";
+    pub const STATUS_MODAL_NORMAL: &'static str = "status.modal.normal";
+    pub const STATUS_MODAL_INSERT: &'static str = "status.modal.insert";
+    pub const STATUS_MODAL_VISUAL: &'static str = "status.modal.visual";
+    pub const STATUS_MODAL_TERMINAL: &'static str = "status.modal.terminal";
 
     pub const PALETTE_INPUT_LINE_HEIGHT: druid::Key<f64> =
         druid::Key::new("lapce.palette_input_line_height");
