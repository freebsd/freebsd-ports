--- src/coredump/_UCD_access_reg_freebsd.c.orig	2018-06-16 00:05:10 UTC
+++ src/coredump/_UCD_access_reg_freebsd.c
@@ -110,6 +110,10 @@ _UCD_access_reg (unw_addr_space_t as,
       Debug(0, "bad regnum:%d\n", regnum);
       return -UNW_EINVAL;
   };
+#elif defined(UNW_TARGET_AARCH64)
+  if (regnum < 0 || regnum >= UNW_AARCH64_FPCR)
+    return -UNW_EINVAL;
+  *valp = ui->prstatus->pr_reg.x[regnum];
 #else
 #error Port me
 #endif
