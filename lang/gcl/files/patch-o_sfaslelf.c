--- ./o/sfaslelf.c.orig	Wed Jul 24 20:05:53 2002
+++ ./o/sfaslelf.c	Sat Sep 13 23:52:25 2003
@@ -23,7 +23,7 @@
  */
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 #define ELF_TARGET_SPARC 1
 #endif
 
@@ -83,7 +83,7 @@
  if (!(symin=fopen(symfile,"r")))
    {perror(symfile);exit(1);};
  if(!fread((char *)&tab,sizeof(tab),1,symin))
-   FEerror("No header",0,0);
+   FEerror("No header",0);
  symbols=malloc(tab.tot_leng);
  c_table.alloc_length=( (PTABLE_EXTRA+ tab.n_symbols));
  (c_table.ptable) = (TABL *) malloc(sizeof(struct node) * c_table.alloc_length);
@@ -196,7 +196,7 @@
    file = fileno(fp);
 
    if (fstat (file, &stat_buf) == -1)
-     FEerror ("Can't fstat(~a): errno %d\n", 1,faslfile);
+     FEerror ("Can't fstat(~a): errno %d\n", 2,faslfile,0);
 
 
    if (use_mmap) {
@@ -303,7 +303,7 @@
    
    relocate_symbols(symbol_table,nsyms,file_h->e_shnum,&init_address);
    if (init_address < 0)
-     { FEerror(0,"Init address not found ");
+     { FEerror("Init address not found ",0);
      }
 
    { 
@@ -317,7 +317,7 @@
 	   {
 	     int index_to_relocate = shp->sh_info;
 	     if (symtab_index != shp->sh_link)
-	       FEerror("unexpected symbol table used");
+	       FEerror("unexpected symbol table used",0);
 	     the_start = start_address + section[index_to_relocate].start;
 	   }
 /*  	 else if (shp->sh_type == SHT_REL */
@@ -332,7 +332,7 @@
 	 else if ( (shp->sh_type == SHT_REL) || (shp->sh_type == SHT_RELA) )
 	   {  if (get_section_number(".rel.stab") == j)
 	         continue;
-	     FEerror("unknown rel type");
+	     FEerror("unknown rel type",0);
 	   }
 	 else
 	   continue;
@@ -520,7 +520,7 @@
     else if (sh_type == SHT_REL)
       a = 0;
     else {
-      FEerror("relocate() error: unknown sh_type in ELF object");
+      FEerror("relocate() error: unknown sh_type in ELF object",0);
       a=0;
     }
     b = (unsigned int) the_start;
@@ -540,9 +540,9 @@
 /*      do_bfd_reloc(ELF32_R_TYPE(reloc_info->r_info),s+a,(unsigned int *)where); */
 /*  #else */
     switch(ELF32_R_TYPE(reloc_info->r_info)){
-#if (defined(__svr4__) || defined(__linux__)) && defined(__i386__)
+#if (defined(__svr4__) || defined(__linux__) || defined(__FreeBSD__)) && defined(__i386__)
     case     R_386_NONE:
-      FEerror("Unsupported ELF type R_386_NONE");
+      FEerror("Unsupported ELF type R_386_NONE",0);
       break;
 
     case     R_386_32:
@@ -556,40 +556,40 @@
       break;
 
     case     R_386_GOT32:
-      FEerror("Unsupported ELF type R_386_GOY32");
+      FEerror("Unsupported ELF type R_386_GOY32",0);
       break;
 
     case     R_386_PLT32:
-      FEerror("Unsupported ELF type R_386_PLT32");
+      FEerror("Unsupported ELF type R_386_PLT32",0);
       break;
 
     case     R_386_COPY:
-      FEerror("Unsupported ELF type R_386_COPY");
+      FEerror("Unsupported ELF type R_386_COPY",0);
       break;
 
     case     R_386_GLOB_DAT:
-      FEerror("Unsupported ELF type R_386_GLOB_DAT");
+      FEerror("Unsupported ELF type R_386_GLOB_DAT",0);
       break;
 
     case     R_386_JMP_SLOT:
-      FEerror("Unsupported ELF type R_386_JMP_SLOT");
+      FEerror("Unsupported ELF type R_386_JMP_SLOT",0);
       break;
 
     case     R_386_RELATIVE:
-      FEerror("Unsupported ELF type R_386_RELATIVE");
+      FEerror("Unsupported ELF type R_386_RELATIVE",0);
       break;
 
     case     R_386_GOTOFF:
-      FEerror("Unsupported ELF type R_386_GOTOFF");
+      FEerror("Unsupported ELF type R_386_GOTOFF",0);
       break;
 
     case     R_386_GOTPC:
-      FEerror("Unsupported ELF type R_386_GOTPC");
+      FEerror("Unsupported ELF type R_386_GOTPC",0);
       break;
 
 #ifdef R_386_NUM
     case     R_386_NUM:
-      FEerror("Unsupported ELF type R_386_NUM");
+      FEerror("Unsupported ELF type R_386_NUM",0);
       break;
 #endif
 
@@ -657,7 +657,7 @@
 	  fflush(stdout);
 	}
     }
-  else{FEerror("symbol table not loaded",0,0);}
+  else{FEerror("symbol table not loaded",0);}
 }
 
 static void
