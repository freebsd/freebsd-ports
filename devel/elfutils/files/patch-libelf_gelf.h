--- libelf/gelf.h.orig	2016-12-28 09:32:00 UTC
+++ libelf/gelf.h
@@ -65,6 +65,10 @@ typedef Elf64_Ehdr GElf_Ehdr;
 typedef Elf64_Shdr GElf_Shdr;
 
 /* Section index.  */
+#ifndef LIBELF_ELF_SECTION_DEFINED
+/* Type for section indices, which are 16-bit quantities.  */
+typedef uint16_t Elf64_Section;
+#endif
 /* XXX This should probably be a larger type in preparation of times when
    regular section indices can be larger.  */
 typedef Elf64_Section GElf_Section;
@@ -110,6 +114,19 @@ typedef Elf64_Versym GElf_Versym;
 
 
 /* Auxiliary vector.  */
+#ifndef LIBELF_ELF_AUXV_T_DEFINED
+typedef struct
+{
+  uint64_t a_type;		/* Entry type */
+  union
+    {
+      uint64_t a_val;		/* Integer value */
+      /* We use to have pointer elements added here.  We cannot do that,
+	 though, since it does not work when using 32-bit definitions
+	 on 64-bit platforms and vice versa.  */
+    } a_un;
+} Elf64_auxv_t;
+#endif
 typedef Elf64_auxv_t GElf_auxv_t;
 
 
