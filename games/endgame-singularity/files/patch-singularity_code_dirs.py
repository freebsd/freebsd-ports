--- singularity/code/dirs.py.orig	2020-07-02 08:18:47 UTC
+++ singularity/code/dirs.py
@@ -54,6 +54,7 @@ version_dir = '1.0'
 dir_defs = (
     ( {"name":"data", "mandatory": True},
         {"parent": "root",        "path": "data",           },
+        {"parent": "share",       "path": "data",           },
     ),
     ( {"name":"i18n", "writable": True},
         {"parent": "files_home",  "path": "i18n",           }, # New XDG dir
@@ -63,6 +64,7 @@ dir_defs = (
         {"parent": "files_home",  "path": "music",          }, # New XDG dir
         {"parent": "old_home",    "path": "music",          }, # Old .endgame dir
         {"parent": "root",        "path": "music",          },
+        {"parent": "share",       "path": "music"           },
     ),
     ( {"name":"sounds", },
         {"parent": "data",        "path": "sounds"          },
@@ -135,6 +137,7 @@ def create_directories(force_single_dir):
         write_dirs["config_home"] = pref_dir_new
         read_dirs["files_home"] = [files_dir_new]
         write_dirs["files_home"] = files_dir_new
+        read_dirs["share"] = ['/usr/local/share/singularity']
 
     # Now find dirs.
     for defs in dir_defs:
