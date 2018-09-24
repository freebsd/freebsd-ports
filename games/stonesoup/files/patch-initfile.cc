--- initfile.cc.orig	2018-09-24 03:59:12 UTC
+++ initfile.cc
@@ -4225,7 +4225,7 @@ static void _bones_rewrite(const string 
         if (dups)
             cout << ", " << dups << " duplicates removed";
         cout << "\n";
-        unlink(filename.c_str());
+        unlink_u(filename.c_str());
         _write_bones(filename, out);
     }
     else
@@ -4241,7 +4241,7 @@ static void _bones_merge(const vector<st
         out.insert(out.end(), ghosts.begin(), ghosts.end());
     }
     if (file_exists(out_name))
-        unlink(out_name.c_str());
+        unlink_u(out_name.c_str());
     if (out.size() == 0)
         cout << "Writing empty bones file";
     else
