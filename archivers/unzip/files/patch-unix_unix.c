--- unzip-5.52.orig/unix/unix.c
+++ unix/unix.c
@@ -1042,8 +1042,6 @@
     ush z_uidgid[2];
     int have_uidgid_flg;
 
-    fclose(G.outfile);
-
 /*---------------------------------------------------------------------------
     If symbolic links are supported, allocate storage for a symlink control
     structure, put the uncompressed "data" and other required info in it, and
@@ -1063,6 +1061,7 @@
             Info(slide, 0x201, ((char *)slide,
               "warning:  symbolic link (%s) failed: mem alloc overflow\n",
               FnFilter1(G.filename)));
+            fclose(G.outfile);
             return;
         }
 
@@ -1070,6 +1069,7 @@
             Info(slide, 0x201, ((char *)slide,
               "warning:  symbolic link (%s) failed: no mem\n",
               FnFilter1(G.filename)));
+            fclose(G.outfile);
             return;
         }
         slnk_entry->next = NULL;
@@ -1079,11 +1079,10 @@
         slnk_entry->fname = slnk_entry->target + ucsize + 1;
         strcpy(slnk_entry->fname, G.filename);
 
-        /* reopen the "link data" file for reading */
-        G.outfile = fopen(G.filename, FOPR);
+        /* move back to the start of the file to re-read the "link data" */
+        rewind(G.outfile);
 
-        if (!G.outfile ||
-            fread(slnk_entry->target, 1, ucsize, G.outfile) != (int)ucsize)
+        if (fread(slnk_entry->target, 1, ucsize, G.outfile) != (int)ucsize)
         {
             Info(slide, 0x201, ((char *)slide,
               "warning:  symbolic link (%s) failed\n",
@@ -1115,12 +1114,20 @@
     }
 #endif
 
+#if (defined(NO_FCHOWN) || defined(NO_FCHMOD))
+    fclose(G.outfile);
+#endif
+
     have_uidgid_flg = get_extattribs(__G__ &(zt.t3), z_uidgid);
 
     /* if -X option was specified and we have UID/GID info, restore it */
     if (have_uidgid_flg) {
         TTrace((stderr, "close_outfile:  restoring Unix UID/GID info\n"));
+#if (defined(NO_FCHOWN) || defined(NO_FCHMOD))
         if (chown(G.filename, (uid_t)z_uidgid[0], (gid_t)z_uidgid[1]))
+#else
+        if (fchown(fileno(G.outfile), (uid_t)z_uidgid[0], (gid_t)z_uidgid[1]))
+#endif
         {
             if (uO.qflag)
                 Info(slide, 0x201, ((char *)slide,
@@ -1133,6 +1140,18 @@
         }
     }
 
+#if (!defined(NO_FCHOWN) && !defined(NO_FCHMOD))
+/*---------------------------------------------------------------------------
+    Change the file permissions from default ones to those stored in the
+    zipfile.
+  ---------------------------------------------------------------------------*/
+
+    if (fchmod(fileno(G.outfile), filtattr(__G__ G.pInfo->file_attr)))
+        perror("chmod (file attributes) error");
+
+    fclose(G.outfile);
+#endif /* !NO_FCHOWN && !NO_FCHMOD */
+
     /* set the file's access and modification times */
     if (utime(G.filename, &(zt.t2))) {
 #ifdef AOS_VS
@@ -1151,6 +1170,7 @@
 #endif /* ?AOS_VS */
     }
 
+#if (defined(NO_FCHOWN) || defined(NO_FCHMOD))
 /*---------------------------------------------------------------------------
     Change the file permissions from default ones to those stored in the
     zipfile.
@@ -1160,6 +1180,7 @@
     if (chmod(G.filename, filtattr(__G__ G.pInfo->file_attr)))
         perror("chmod (file attributes) error");
 #endif
+#endif /* NO_FCHOWN || NO_FCHMOD */
 
 } /* end function close_outfile() */
 
@@ -1640,7 +1661,6 @@
 
             if ((long)LG(dlen) > 0)
             {
-                G.outfile = fopen(G.filename,"r+");
                 fseek(G.outfile, -8, SEEK_END);
                 fread(&ntc, 8, 1, G.outfile);
                 if(ntc.id != *(long *)"XTcc")
@@ -1650,7 +1670,6 @@
                     fwrite (&ntc, 8, 1, G.outfile);
                 }
                 Info(slide, 0x201, ((char *)slide, "QData = %d", LG(dlen)));
-                fclose(G.outfile);
             }
             return;     /* finished, cancel further extra field scanning */
           }
