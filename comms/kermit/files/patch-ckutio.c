--- ckutio.c.orig
+++ ckutio.c
@@ -4879,8 +4879,18 @@
 #ifdef USETTYLOCK
     haslock = 0;                        /* Not locked yet. */
     *flfnam = '\0';			/* Lockfile name is empty. */
+#ifdef __FreeBSD__
+    char *devname;
+    if ((devname = xxlast(ttdev,'/')) != NULL)
+#if __FreeBSD_version < 800045
+      ckstrncpy(lockname,devname+1,DEVNAMLEN);
+#else
+      ckstrncat(lockname,devname+1,DEVNAMLEN-ckstrncpy(lockname,"pts",4));
+#endif
+#else
     if (!strncmp(ttdev,"/dev/",5) && ttdev[5])
       ckstrncpy(lockname,ttdev+5,DEVNAMLEN);
+#endif
     else
       ckstrncpy(lockname,ttdev,DEVNAMLEN);
 /*
