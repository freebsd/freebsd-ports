--- initfile.cc.orig	2021-08-20 10:45:00 UTC
+++ initfile.cc
@@ -4529,7 +4529,7 @@ static void _bones_rewrite(const string filename, cons
         if (dups)
             cout << ", " << dups << " duplicates removed";
         cout << "\n";
-        unlink(filename.c_str());
+        unlink_u(filename.c_str());
         _write_bones(filename, out);
     }
     else
@@ -4554,7 +4554,7 @@ static void _bones_merge(const vector<string> files, c
             break;
     }
     if (file_exists(out_name))
-        unlink(out_name.c_str());
+        unlink_u(out_name.c_str());
     if (out.size() == 0)
         cout << "Writing empty bones file";
     else
