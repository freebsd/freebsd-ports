--- sql/range_optimizer/index_range_scan_plan.cc.orig	2023-11-24 10:33:10 UTC
+++ sql/range_optimizer/index_range_scan_plan.cc
@@ -1015,11 +1015,11 @@ static bool null_part_in_key(KEY_PART *key_part, const
   return false;
 }
 
-// TODO(sgunders): This becomes a bit simpler with C++20's string_view
-// constructors.
-static inline std::basic_string_view<uchar> make_string_view(const uchar *start,
-                                                             const uchar *end) {
-  return {start, static_cast<size_t>(end - start)};
+static inline bool equal(const uchar *start1, const uchar *end1,
+                         const uchar *start2, const uchar *end2) {
+  auto diff1 = end1 - start1;
+  auto diff2 = end2 - start2;
+  return diff1 == diff2 && memcmp(start1, start2, diff1) == 0;
 }
 
 /**
@@ -1082,8 +1082,7 @@ static bool get_ranges_from_tree_given_base(
         node->next_key_part->type == SEL_ROOT::Type::KEY_RANGE &&
         node->next_key_part->root->part == part + 1) {
       if (node->min_flag == 0 && node->max_flag == 0 &&
-          make_string_view(min_key, tmp_min_key) ==
-              make_string_view(max_key, tmp_max_key)) {
+          equal(min_key, tmp_min_key, max_key, tmp_max_key)) {
         // This range was an equality predicate, and we have more
         // keyparts to scan, so use its range as a base for ranges on
         // the next keypart(s). E.g. if we have (a = 3) on this keypart,
@@ -1159,8 +1158,7 @@ static bool get_ranges_from_tree_given_base(
       else
         flag |= NO_MAX_RANGE;
     }
-    if (flag == 0 && make_string_view(base_min_key, tmp_min_key) ==
-                         make_string_view(base_max_key, tmp_max_key)) {
+    if (flag == 0 && equal(base_min_key, tmp_min_key, base_max_key, tmp_max_key)) {
       flag |= EQ_RANGE;
       /*
         Note that keys which are extended with PK parts have no
