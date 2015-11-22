--- support/utilgen.c.orig	2015-10-11 18:41:42 UTC
+++ support/utilgen.c
@@ -18,6 +18,7 @@
 # define _LARGEFILE64_SOURCE
 #endif
 #include <stdio.h>
+#include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/types.h>
@@ -181,6 +182,39 @@ void gen_stat(void)
     printf("   end record;\n");
     printf("   pragma Convention (C_Pass_By_Copy, Stat_Type);\n");
     printf("\n");
+#elif defined(__DragonFly__)
+    struct stat st;
+
+    gen_type("uint16_t", UNSIGNED, sizeof(uint16_t));
+    gen_type("u_int32_t", UNSIGNED, sizeof(u_int32_t));
+    gen_type("int32_t", SIGNED, sizeof(int32_t));
+    gen_type("int64_t", SIGNED, sizeof(int64_t));
+
+    printf("   STAT_NAME  : constant String := \"stat\";\n");
+    printf("   FSTAT_NAME : constant String := \"fstat\";\n");
+    printf("   type Stat_Type is record\n");
+    printf("      st_ino      : ino_t;\n");
+    printf("      st_nlink    : nlink_t;\n");
+    printf("      st_dev      : dev_t;\n");
+    printf("      st_mode     : mode_t;\n");
+    printf("      st_padding1 : uint16_t;\n");
+    printf("      st_uid      : uid_t;\n");
+    printf("      st_gid      : gid_t;\n");
+    printf("      st_rdev     : dev_t;\n");
+    printf("      st_atim     : Timespec;\n");
+    printf("      st_mtim     : Timespec;\n");
+    printf("      st_ctim     : Timespec;\n");
+    printf("      st_size     : off_t;\n");
+    printf("      st_blocks   : int64_t;\n");
+    printf("      st_blksize  : u_int32_t;\n");
+    printf("      st_flags    : u_int32_t;\n");
+    printf("      st_gen      : u_int32_t;\n");
+    printf("      st_lspare   : int32_t;\n");
+    printf("      st_qspare1  : int64_t;\n");
+    printf("      st_qspare2  : int64_t;\n");
+    printf("   end record;\n");
+    printf("   pragma Convention (C_Pass_By_Copy, Stat_Type);\n");
+    printf("\n");
 #elif defined(__FreeBSD__)
     struct stat st;
 
