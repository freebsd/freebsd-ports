--- setup.py.orig	Sun Apr 28 20:35:22 2002
+++ setup.py	Sun Apr 28 20:37:24 2002
@@ -119,7 +119,7 @@
 for sf in shared_files:
     sf.base_dir = '$base/share/narval'
  
-data_files = documentation_files + shared_files
+data_files = shared_files
 #Do this after we set the base_dir on all of the rest
 data_files.append(Data_Files(copy_to='',
                              files=['conf/narval.conf',
@@ -144,12 +144,6 @@
 
     # Command function overrides
     cmdclass=DistExt.Commands,
-
-    # Install data files to doc/{name}-{version}/
-    options={'install' : {'install_data' :
-                          '$base/doc/$dist_name'+'-'+doc_version,
-                          },
-             },
 
     packages=['narval',
               'narval.dom',
