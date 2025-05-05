--- third_party/blink/renderer/build/scripts/gperf.py.orig	2025-01-06 14:31:29 UTC
+++ third_party/blink/renderer/build/scripts/gperf.py
@@ -35,10 +35,13 @@ def generate_gperf(gperf_path, gperf_input, gperf_args
         # https://savannah.gnu.org/bugs/index.php?53028
         gperf_output = re.sub(r'\bregister ', '', gperf_output)
         # -Wimplicit-fallthrough needs an explicit fallthrough statement,
-        # so replace gperf's /*FALLTHROUGH*/ comment with the statement.
-        # https://savannah.gnu.org/bugs/index.php?53029
-        gperf_output = gperf_output.replace('/*FALLTHROUGH*/',
-                                            '  [[fallthrough]];')
+        # so replace gperf 3.1's /*FALLTHROUGH*/ comment with the statement.
+        # https://savannah.gnu.org/bugs/index.php?53029 (fixed in 3.2)
+        if re.search(
+                r'/\* C\+\+ code produced by gperf version 3\.[01](\.\d+)? \*/',
+                gperf_output):
+            gperf_output = gperf_output.replace('/*FALLTHROUGH*/',
+                                                '  [[fallthrough]];')
         # -Wpointer-to-int-cast warns about casting pointers to smaller ints
         # Replace {(int)(long)&(foo), bar} with
         # {static_cast<int>(reinterpret_cast<uintptr_t>(&(foo)), bar}
