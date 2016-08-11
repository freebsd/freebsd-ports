--- libelf/libelf.h.orig	2014-08-18 19:48:26 UTC
+++ libelf/libelf.h
@@ -74,7 +74,7 @@ typedef struct
   Elf_Type d_type;		/* Type of this piece of data.  */
   unsigned int d_version;	/* ELF version.  */
   size_t d_size;		/* Size in bytes.  */
-  loff_t d_off;			/* Offset into section.  */
+  off_t d_off;			/* Offset into section.  */
   size_t d_align;		/* Alignment in section.  */
 } Elf_Data;
 
@@ -136,7 +136,7 @@ typedef struct
   uid_t ar_uid;			/* User ID.  */
   gid_t ar_gid;			/* Group ID.  */
   mode_t ar_mode;		/* File mode.  */
-  loff_t ar_size;		/* File size.  */
+  off_t ar_size;		/* File size.  */
   char *ar_rawname;		/* Original name of archive member.  */
 } Elf_Arhdr;
 
@@ -177,13 +177,13 @@ extern Elf_Cmd elf_next (Elf *__elf);
 extern int elf_end (Elf *__elf);
 
 /* Update ELF descriptor and write file to disk.  */
-extern loff_t elf_update (Elf *__elf, Elf_Cmd __cmd);
+extern off_t elf_update (Elf *__elf, Elf_Cmd __cmd);
 
 /* Determine what kind of file is associated with ELF.  */
 extern Elf_Kind elf_kind (Elf *__elf) __attribute__ ((__pure__));
 
 /* Get the base offset for an object file.  */
-extern loff_t elf_getbase (Elf *__elf);
+extern off_t elf_getbase (Elf *__elf);
 
 
 /* Retrieve file identification data.  */
@@ -301,7 +301,7 @@ extern Elf_Data *elf_newdata (Elf_Scn *_
    would be for TYPE.  The resulting Elf_Data pointer is valid until
    elf_end (ELF) is called.  */
 extern Elf_Data *elf_getdata_rawchunk (Elf *__elf,
-				       loff_t __offset, size_t __size,
+				       off_t __offset, size_t __size,
 				       Elf_Type __type);
 
 
@@ -313,7 +313,7 @@ extern char *elf_strptr (Elf *__elf, siz
 extern Elf_Arhdr *elf_getarhdr (Elf *__elf);
 
 /* Return offset in archive for current file ELF.  */
-extern loff_t elf_getaroff (Elf *__elf);
+extern off_t elf_getaroff (Elf *__elf);
 
 /* Select archive element at OFFSET.  */
 extern size_t elf_rand (Elf *__elf, size_t __offset);
