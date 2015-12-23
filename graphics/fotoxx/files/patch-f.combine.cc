--- f.combine.cc.orig	2015-05-01 09:40:38 UTC
+++ f.combine.cc
@@ -6475,7 +6475,7 @@ void m_pano_PT(GtkWidget *, cchar *)    
       goto cleanup;
    }
 
-   olddir = get_current_dir_name();                                        //  save curr. directory
+   olddir = getcwd(NULL,PATH_MAX);                                         //  save curr. directory
 
    err = chdir(tempdir);                                                   //  use /tmp/fotoxx-xxxxx
    if (err) {
