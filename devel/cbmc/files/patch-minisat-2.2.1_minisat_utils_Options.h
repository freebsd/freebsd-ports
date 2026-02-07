--- minisat-2.2.1/minisat/utils/Options.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/utils/Options.h
@@ -60,7 +60,7 @@ class Option
     struct OptionLt {
         bool operator()(const Option* x, const Option* y) {
             int test1 = strcmp(x->category, y->category);
-            return test1 < 0 || test1 == 0 && strcmp(x->type_name, y->type_name) < 0;
+            return test1 < 0 || (test1 == 0 && strcmp(x->type_name, y->type_name) < 0);
         }
     };
 
@@ -282,15 +282,15 @@ class Int64Option : public Option
         if (range.begin == INT64_MIN)
             fprintf(stderr, "imin");
         else
-            fprintf(stderr, "%4"PRIi64, range.begin);
+            fprintf(stderr, "%4" PRIi64, range.begin);
 
         fprintf(stderr, " .. ");
         if (range.end == INT64_MAX)
             fprintf(stderr, "imax");
         else
-            fprintf(stderr, "%4"PRIi64, range.end);
+            fprintf(stderr, "%4" PRIi64, range.end);
 
-        fprintf(stderr, "] (default: %"PRIi64")\n", value);
+        fprintf(stderr, "] (default: %" PRIi64 ")\n", value);
         if (verbose){
             fprintf(stderr, "\n        %s\n", description);
             fprintf(stderr, "\n");
