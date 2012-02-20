--- kernel/OS/FreeBSD/os_freebsd.c	2012-02-02 17:46:03.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2012-02-20 12:58:46.000000000 -0500
@@ -16,6 +16,7 @@
 #include "midi_core.h"
 #include <oss_pci.h>
 #include <sys/conf.h>
+#include <sys/module.h>
 #include <sys/proc.h>
 #include <sys/sx.h>
 #include <sys/mman.h>
@@ -315,7 +316,7 @@
 
   if (cards[cardnum]->name != NULL)
     strncpy (ci->longname, cards[cardnum]->name, 128);
-  ci->shortname[127] = 0;
+  ci->longname[127] = 0;
 
   if (cards[cardnum]->nick != NULL)
     strncpy (ci->shortname, cards[cardnum]->nick, 16);
@@ -413,8 +414,19 @@
 
   if (!(flags & CHDEV_VIRTUAL) && (name != NULL))
     {
+#if __FreeBSD_version >= 900023
+      bsd_cdev =
+	make_dev_credf (MAKEDEV_CHECKNAME, &oss_cdevsw, num, NULL,
+			UID_ROOT, GID_WHEEL, 0666, name, 0);
+      if (bsd_cdev == NULL)
+	{
+	  cmn_err (CE_WARN, "Cannot allocate device node /dev/%s\n", name);
+	  return;
+	}
+#else
       bsd_cdev =
 	make_dev (&oss_cdevsw, num, UID_ROOT, GID_WHEEL, 0666, name, 0);
+#endif
       cdev->info = bsd_cdev;
     }
 }
@@ -604,6 +616,12 @@
 {
   oss_device_t *osdev;
 
+  if (module_lookupbyname("sound") != NULL)
+    {
+      cmn_err (CE_WARN, "Open Sound System conflicts with FreeBSD driver\n");
+      cmn_err (CE_CONT, "Please remove sound(4) from kernel or unload it\n");
+      return EBUSY;
+    }
   if ((osdev = PMALLOC (NULL, sizeof (*osdev))) == NULL)
     {
       return ENOSPC;
