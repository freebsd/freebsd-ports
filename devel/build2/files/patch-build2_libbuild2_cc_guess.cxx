commit 0e1b73e3b43bca7c1d77ed669b364819ad211da9
Author: Boris Kolpackov <boris@codesynthesis.com>
Date:   2024-02-02T11:41:33+02:00

    Handle unseparated `rc` and `git` suffixes in Clang version (GH issue #360)

--- build2/libbuild2/cc/guess.cxx.orig	2023-06-19 05:26:33 UTC
+++ build2/libbuild2/cc/guess.cxx
@@ -2421,6 +2421,12 @@ namespace build2
       //
       // emcc (...) 2.0.8
       //
+      // Pre-releases of the vanilla Clang append `rc` or `git` to the
+      // version, unfortunately without a separator. So we will handle these
+      // ad hoc. For example:
+      //
+      // FreeBSD clang version 18.1.0rc (https://github.com/llvm/llvm-project.git llvmorg-18-init-18361-g22683463740e)
+      //
       auto extract_version = [] (const string& s, bool patch, const char* what)
         -> compiler_version
       {
@@ -2435,8 +2441,28 @@ namespace build2
           // end of the word position (first space). In fact, we can just
           // check if it is >= e.
           //
-          if (s.find_first_not_of ("1234567890.", b, 11) >= e)
+          size_t p (s.find_first_not_of ("1234567890.", b, 11));
+          if (p >= e)
             break;
+
+          // Handle the unseparated `rc` and `git` suffixes.
+          //
+          if (p != string::npos)
+          {
+            if (p + 2 == e && (e - b) > 2 &&
+                s[p] == 'r' && s[p + 1] == 'c')
+            {
+              e -= 2;
+              break;
+            }
+
+            if (p + 3 == e && (e - b) > 3 &&
+                s[p] == 'g' && s[p + 1] == 'i' && s[p + 2] == 't')
+            {
+              e -= 3;
+              break;
+            }
+          }
         }
 
         if (b == e)
@@ -2472,8 +2498,15 @@ namespace build2
         ver.patch = next ("patch", patch);
 
         if (e != s.size ())
-          ver.build.assign (s, e + 1, string::npos);
+        {
+          // Skip the separator (it could also be unseparated `rc` or `git`).
+          //
+          if (s[e] == ' ' || s[e] == '-')
+            e++;
 
+          ver.build.assign (s, e, string::npos);
+        }
+
         return ver;
       };
 
@@ -2496,7 +2529,10 @@ namespace build2
 
         // Some overrides for testing.
         //
+        //string s (xv != nullptr ? *xv : "");
+        //
         //s = "clang version 3.7.0 (tags/RELEASE_370/final)";
+        //s = "FreeBSD clang version 18.1.0rc (https://github.com/llvm/llvm-project.git llvmorg-18-init-18361-g22683463740e)";
         //
         //gr.id.variant = "apple";
         //s = "Apple LLVM version 7.3.0 (clang-703.0.16.1)";
