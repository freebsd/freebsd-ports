--- ld/writebin.c.orig	1994-02-19 22:37:23 UTC
+++ ld/writebin.c
@@ -14,6 +14,19 @@ static long bdataoffset;
 #  ifdef STANDARD_GNU_A_OUT
 #   include <a.out.h>
 #   define RELOC_INFO_SIZE 8	/* unportable bitfields - bcc doesn't pack */
+struct a_out_nlist
+{
+    union
+    {
+	char n_name[4];
+	char n_strx[4];
+    }
+	n_un;
+    unsigned char n_type;
+    char n_other;
+    short n_desc;
+    char n_value[4];
+};
 #  else
 #   include "bsd-a.out.h"
 #   define RELOC_INFO_SIZE (sizeof (struct relocation_info))
@@ -209,7 +222,7 @@ bool_pt arguzp;
     char *commandname;
 #endif
     char *cptr;
-    struct nlist extsym;
+    struct a_out_nlist extsym;
     flags_t flags;
     struct modstruct *modptr;
     fastin_t seg;
@@ -918,7 +931,7 @@ PRIVATE void writeheader()
 #ifdef N_SET_MAGIC
     N_SET_MAGIC(header, OMAGIC);
 #else
-    *(unsigned short *) &header.a_magic = OMAGIC;  /* XXX - works for 386BSD */
+    u2c2((char *) &header.a_magic, OMAGIC);
 #endif
 #else
     header.a_magic[0] = A_MAGIC0;
