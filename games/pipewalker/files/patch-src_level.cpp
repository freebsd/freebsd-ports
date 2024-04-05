--- src/level.cpp.orig	2024-01-14 09:10:02 UTC
+++ src/level.cpp
@@ -15,8 +15,8 @@ void Level::generate()
     std::fill(cells.begin(), cells.end(), Cell {});
 
     // install sender (server)
-    sender.x = mtrand::get(1ul, width - 1);
-    sender.y = mtrand::get(1ul, height - 1);
+    sender.x = mtrand::get((size_t)1, width - 1);
+    sender.y = mtrand::get((size_t)1, height - 1);
     get_cell(sender).object = Cell::Sender;
 
     const size_t max_recievers = cells.size() / 5;
@@ -146,7 +146,7 @@ void Level::add_reciever()
     }
 
     // get random position
-    const size_t free_index = mtrand::get(0ul, free_cells.size());
+    const size_t free_index = mtrand::get((size_t)0, free_cells.size());
     const Position& reciever = free_cells[free_index];
 
     // find path from receiver to sender
@@ -176,8 +176,8 @@ bool Level::find_path(const Position& from, std::set<P
         sides.push_back(Side::Top);
         sides.push_back(Side::Bottom);
         for (size_t i = 0; i < 4; ++i) {
-            const size_t index0 = mtrand::get(0ul, sides.size());
-            const size_t index1 = mtrand::get(0ul, sides.size());
+            const size_t index0 = mtrand::get((size_t)0, sides.size());
+            const size_t index1 = mtrand::get((size_t)0, sides.size());
             std::iter_swap(sides.begin() + index0, sides.begin() + index1);
         }
     } else {
