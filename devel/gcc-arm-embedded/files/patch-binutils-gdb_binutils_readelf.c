--- binutils-gdb/binutils/readelf.c.orig	2024-11-20 17:30:17 UTC
+++ binutils-gdb/binutils/readelf.c
@@ -23275,7 +23275,7 @@ process_v850_notes (Filedata * filedata, uint64_t offs
 
       /* Prevent out-of-bounds indexing.  */
       if (   inote.namedata + inote.namesz > end
-	  || inote.namedata + inote.namesz < inote.namedata)
+	  || (uintptr_t)inote.namedata + inote.namesz < (uintptr_t)inote.namedata)
         {
           warn (_("corrupt namesz found in note at offset %#zx\n"),
                 (char *) external - (char *) pnotes);
