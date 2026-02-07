--- libexplain/buffer/mount_flags.c.orig
+++ libexplain/buffer/mount_flags.c
@@ -148,6 +148,7 @@
      * information and must be discarded.
      */
     first = 1;
+#if defined(MS_MGC_MSK) && defined(MS_MGC_VAL)
     if ((flags & MS_MGC_MSK) == MS_MGC_VAL)
     {
         flags &= ~MS_MGC_MSK;
@@ -156,7 +157,9 @@
             return;
         first = 0;
     }
-    else if (flags == 0)
+    else
+#endif
+    if (flags == 0)
     {
         explain_string_buffer_putc(sb, '0');
         return;
