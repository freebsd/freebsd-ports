diff -ubwr ./tccelf.c ../../work.2/tcc-0.9.25/tccelf.c
--- ./tccelf.c	2009-05-18 16:27:06.000000000 +0200
+++ ../../work.2/tcc-0.9.25/tccelf.c	2009-11-29 02:12:36.000000000 +0100
@@ -1273,7 +1273,7 @@
 
 /* name of ELF interpreter */
 #if defined __FreeBSD__
-static char elf_interp[] = "/usr/libexec/ld-elf.so.1";
+static char elf_interp[] = "/libexec/ld-elf.so.1";
 #elif defined TCC_ARM_EABI
 static char elf_interp[] = "/lib/ld-linux.so.3";
 #elif defined(TCC_TARGET_X86_64)
@@ -1306,6 +1306,31 @@
     }
 }
 
+#if defined(__FreeBSD__)
+#define	HAVE_PHDR	1
+#define	EXTRA_RELITEMS	14
+
+/* move the relocation value from .dynsym to .got */
+void patch_dynsym_undef(TCCState *s1, Section *s)
+{
+    uint32_t *gotd = (void *)s1->got->data;
+    ElfW(Sym) *sym, *sym_end;
+
+    gotd += 3;	// dummy entries in .got
+    /* relocate symbols in .dynsym */
+    sym_end = (ElfW(Sym) *)(s->data + s->data_offset);
+    for (sym = (ElfW(Sym) *)s->data + 1; sym < sym_end; sym++) {
+	if (sym->st_shndx == SHN_UNDEF) {
+	    *gotd++ = sym->st_value + 6; // XXX 6 is magic ?
+	    sym->st_value = 0;
+	}
+    }
+}
+#else
+#define	HAVE_PHDR	0
+#define	EXTRA_RELITEMS	9
+#endif
+
 /* output an ELF file */
 /* XXX: suppress unneeded sections */
 int elf_output_file(TCCState *s1, const char *filename)
@@ -1324,6 +1349,7 @@
     ElfW(Sym) *sym;
     int type, file_type;
     unsigned long rel_addr, rel_size;
+    unsigned long bss_addr, bss_size;
     
     file_type = s1->output_type;
     s1->nb_errors = 0;
@@ -1351,11 +1377,15 @@
             
             if (file_type == TCC_OUTPUT_EXE) {
                 char *ptr;
+		/* allow override the dynamic loader */
+		char *elfint = getenv("LD_SO");
+		if (elfint == NULL)
+		    elfint = elf_interp;
                 /* add interpreter section only if executable */
                 interp = new_section(s1, ".interp", SHT_PROGBITS, SHF_ALLOC);
                 interp->sh_addralign = 1;
-                ptr = section_ptr_add(interp, sizeof(elf_interp));
-                strcpy(ptr, elf_interp);
+                ptr = section_ptr_add(interp, 1+strlen(elfint));
+                strcpy(ptr, elfint);
             }
         
             /* add dynamic symbol table */
@@ -1514,7 +1544,7 @@
 
             /* add necessary space for other entries */
             saved_dynamic_data_offset = dynamic->data_offset;
-            dynamic->data_offset += sizeof(ElfW(Dyn)) * 9;
+            dynamic->data_offset += sizeof(ElfW(Dyn)) * EXTRA_RELITEMS;
         } else {
             /* still need to build got entries in case of static link */
             build_got_entries(s1);
@@ -1543,7 +1573,7 @@
         break;
     case TCC_OUTPUT_EXE:
         if (!s1->static_link)
-            phnum = 4;
+            phnum = 4 + HAVE_PHDR;
         else
             phnum = 2;
         break;
@@ -1620,10 +1650,11 @@
         rel_size = 0;
         rel_addr = 0;
 
+ 	bss_addr = bss_size = 0;
         /* leave one program header for the program interpreter */
         ph = &phdr[0];
         if (interp)
-            ph++;
+            ph += 1 + HAVE_PHDR;
 
         for(j = 0; j < 2; j++) {
             ph->p_type = PT_LOAD;
@@ -1685,9 +1716,20 @@
                     }
                     /* update dynamic relocation infos */
                     if (s->sh_type == SHT_RELX) {
+#if defined(__FreeBSD__)
+                        if (!strcmp(strsec->data + s->sh_name, ".rel.got")) { // rel_size == 0) {
+                            rel_addr = addr;
+			    rel_size += s->sh_size;	// XXX only first rel.
+			}
+                        if (!strcmp(strsec->data + s->sh_name, ".rel.bss")) { // rel_size == 0) {
+                            bss_addr = addr;
+			    bss_size = s->sh_size;	// XXX only first rel.
+			}
+#else
                         if (rel_size == 0)
                             rel_addr = addr;
                         rel_size += s->sh_size;
+#endif
                     }
                     addr += s->sh_size;
                     if (s->sh_type != SHT_NOBITS)
@@ -1715,6 +1757,21 @@
         if (interp) {
             ph = &phdr[0];
             
+#if defined(__FreeBSD__)
+	    {
+		int len = phnum * sizeof(ElfW(Phdr));
+
+		ph->p_type = PT_PHDR;
+		ph->p_offset = sizeof(ElfW(Ehdr));
+		ph->p_vaddr = interp->sh_addr - len;
+		ph->p_paddr = ph->p_vaddr;
+		ph->p_filesz = ph->p_memsz = len;
+		ph->p_flags = PF_R | PF_X;
+		ph->p_align = 4; // interp->sh_addralign;
+		ph++;
+	    }
+#endif
+
             ph->p_type = PT_INTERP;
             ph->p_offset = interp->sh_offset;
             ph->p_vaddr = interp->sh_addr;
@@ -1815,10 +1872,19 @@
             put_dt(dynamic, DT_RELASZ, rel_size);
             put_dt(dynamic, DT_RELAENT, sizeof(ElfW_Rel));
 #else
+#if defined(__FreeBSD__)
+            put_dt(dynamic, DT_PLTGOT, s1->got->sh_addr);
+            put_dt(dynamic, DT_PLTRELSZ, rel_size);
+            put_dt(dynamic, DT_JMPREL, rel_addr);
+            put_dt(dynamic, DT_PLTREL, DT_REL);
+            put_dt(dynamic, DT_REL, bss_addr);
+            put_dt(dynamic, DT_RELSZ, bss_size);
+#else
             put_dt(dynamic, DT_REL, rel_addr);
             put_dt(dynamic, DT_RELSZ, rel_size);
             put_dt(dynamic, DT_RELENT, sizeof(ElfW_Rel));
 #endif
+#endif
             if (s1->do_debug)
                 put_dt(dynamic, DT_DEBUG, 0);
             put_dt(dynamic, DT_NULL, 0);
@@ -1950,6 +2016,10 @@
         for(i=1;i<s1->nb_sections;i++) {
             s = s1->sections[section_order[i]];
             if (s->sh_type != SHT_NOBITS) {
+#if defined(__FreeBSD__)
+		if (s->sh_type == SHT_DYNSYM)
+		    patch_dynsym_undef(s1, s);
+#endif
                 while (offset < s->sh_offset) {
                     fputc(0, f);
                     offset++;
