--- p_unix.cpp.orig	Wed Sep  4 00:18:07 2002
+++ p_unix.cpp	Tue Feb 17 08:44:07 2004
@@ -380,6 +380,8 @@
         // now check the ELF header
         if (memcmp(buf+8, "FreeBSD", 7) == 0)   // branded
             exetype = 0;
+        if (buf[7] == 9)                        // FreeBSD
+            exetype = 0;
         if (get_le16(buf+16) != 2)              // e_type - executable
             exetype = 0;
         if (get_le16(buf+18) != 3)              // e_machine - Intel 80386
@@ -404,8 +406,8 @@
         // FIXME: N_TRSIZE, N_DRSIZE
         // FIXME: check for aout shared libraries
     }
-#if defined(__linux__)
-    // only compress scripts when running under Linux
+#if defined(__linux__) || defined(__FreeBSD__)
+    // only compress scripts when running under Linux or FreeBSD
     else if (!memcmp(buf, "#!/", 3))                    // #!/bin/sh
         exetype = -1;
     else if (!memcmp(buf, "#! /", 4))                   // #! /bin/sh
@@ -431,7 +433,8 @@
     //   also, we sleep much longer when compressing a script.
     patch_le32(loader,lsize,"UPX5",mmapsize);
     patch_le32(loader,lsize,"UPX4",exetype > 0 ? 3 : 15);   // sleep time
-    patch_le32(loader,lsize,"UPX3",exetype > 0 ? 0 : 0x7fffffff);
+    if (exetype != 3)
+        patch_le32(loader,lsize,"UPX3",exetype > 0 ? 0 : 0x7fffffff);
     patch_le32(loader,lsize,"UPX2",progid);
     patch_le32(loader,lsize,"UPX1",lsize);
 
@@ -457,6 +460,65 @@
     set_le32(loader + 116, adler);
 }
 
+/*************************************************************************
+// FreeBSD/i386 specific
+**************************************************************************/
+
+static const
+#include "stub/l_b_n2b.h"
+static const
+#include "stub/l_b_n2d.h"
+static const
+#include "stub/l_b_n2e.h"
+
+
+const upx_byte *PackFreeBSDI386::getLoader() const
+{
+    if (M_IS_NRV2B(opt->method))
+        return freebsd_i386_nrv2b_loader;
+    if (M_IS_NRV2D(opt->method))
+        return freebsd_i386_nrv2d_loader;
+    if (M_IS_NRV2E(opt->method))
+        return freebsd_i386_nrv2e_loader;
+    return NULL;
+}
+
+int PackFreeBSDI386::getLoaderSize() const
+{
+    if (M_IS_NRV2B(opt->method))
+        return sizeof(freebsd_i386_nrv2b_loader);
+    if (M_IS_NRV2D(opt->method))
+        return sizeof(freebsd_i386_nrv2d_loader);
+    if (M_IS_NRV2E(opt->method))
+        return sizeof(freebsd_i386_nrv2e_loader);
+    return 0;
+}
+
+bool PackFreeBSDI386::canPack()
+{
+    unsigned char buf[52];      // sizeof(ELF_LE32_Ehdr)
+    exetype = 0;
+
+    fi->readx(buf,sizeof(buf));
+    fi->seek(0, SEEK_SET);
+    if (!memcmp(buf, "\x7f\x45\x4c\x46\x01\x01\x01", 7)) // ELF 32-bit LSB
+    {
+        exetype = 3;
+        // now check the ELF header
+        if (buf[7] != 9)                        // FreeBSD
+            exetype = 0;
+        if (get_le16(buf+16) != 2)              // e_type - executable
+            exetype = 0;
+        if (get_le16(buf+18) != 3)              // e_machine - Intel 80386
+            exetype = 0;
+        if (get_le32(buf+20) != 1)              // e_version
+            exetype = 0;
+        if (get_le16(buf+44) < 1)               // e_phnum
+            exetype = 0;
+    }
+
+    return PackUnix::canPack();
+}
 
 /*
 vi:ts=4:et
