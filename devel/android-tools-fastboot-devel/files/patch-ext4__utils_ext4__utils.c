Avoid conflict with slightly different |struct uuid| in <sys/uuid.h>.

  ext4_utils/ext4_utils.c:64:8: error: redefinition of 'struct uuid'
   struct uuid {
          ^
  In file included from /usr/include/sys/disklabel.h:47:0,
                   from /usr/include/sys/diskslice.h:70,
                   from ext4_utils/ext4_utils.c:53:
  /usr/include/sys/uuid.h:45:8: note: originally defined here
   struct uuid {
          ^

--- ext4_utils/ext4_utils.c.orig	2015-07-18 11:53:50 UTC
+++ ext4_utils/ext4_utils.c
@@ -53,6 +61,7 @@ struct sparse_file *ext4_sparse_file;
 jmp_buf setjmp_env;
 
 /* Definition from RFC-4122 */
+#define uuid ext4_uuid
 struct uuid {
     u32 time_low;
     u16 time_mid;
