--- libexplain/buffer/errno/mount.c.orig
+++ libexplain/buffer/errno/mount.c
@@ -384,8 +384,10 @@
    target_fc.st_mode = S_IFDIR;
    target_fc.must_exist = 1;
 
+#if defined(MS_MGC_MSK) && defined(MS_MGC_VAL)
    if ((flags & MS_MGC_MSK) & MS_MGC_VAL)
        flags &= ~MS_MGC_MSK;
+#endif
 
     switch (errnum)
     {
@@ -425,6 +427,7 @@
          * Or, mounting a read-only file system was attempted without
          * giving the MS_RDONLY flag.
          */
+#if defined(MS_RDONLY)
         if (!(flags & MS_RDONLY))
         {
             int fd = open(source, O_RDONLY, 0);
@@ -444,11 +447,13 @@
             }
             close(fd);
         }
+#endif
 
         /*
          * Or, the block device source is located on a file system
          * mounted with the MS_NODEV option.
          */
+#if defined(MS_NODEV)
         {
             struct statvfs info;
             if (statvfs(source, &info) >  0)
@@ -469,6 +474,7 @@
                 }
             }
         }
+#endif
 
         /* no idea */
         explain_buffer_eacces(sb, target, "target", &target_fc);
@@ -488,6 +494,7 @@
          * Or, it cannot be remounted read-only, because it still holds
          * files open for writing.
          */
+#if defined(MS_RDONLY) && defined(MS_REMOUNT)
         {
             unsigned long flags2 = MS_RDONLY | MS_REMOUNT;
             if ((flags & flags2) == flags2)
@@ -513,6 +520,7 @@
             /* FIXME: tell th user *which* block device */
             return;
         }
+#endif
 
         /*
          * Or,
@@ -606,6 +614,7 @@
          * Or, a remount (MS_REMOUNT) was attempted, but source was not
          * already mounted on target.
          */
+#if defined(MS_REMOUNT)
         if ((flags & MS_REMOUNT) && !source_mounted_on_target(source, target))
         {
             explain_buffer_gettext
@@ -617,11 +626,13 @@
             );
             return;
         }
+#endif
 
         /*
          * Or, a move (MS_MOVE) was attempted, but source was not a
          * mount point, or was '/'.
          */
+#if defined(MS_MOVE)
         if (flags & MS_MOVE)
         {
              if (0 == strcmp(target, "/"))
@@ -645,6 +656,7 @@
                 return;
             }
         }
+#endif
 
         /*
          * (we have ruled out most everything else)
