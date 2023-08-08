--- hotspot/agent/src/os/bsd/symtab.c.orig	2023-02-18 20:21:09 UTC
+++ hotspot/agent/src/os/bsd/symtab.c
@@ -204,6 +204,38 @@ struct elf_section {
   void       *c_data;
 };
 
+/* Find an ELF section.  */
+static struct elf_section *find_section_by_name(char *name,
+						int fd,
+						ELF_EHDR *ehdr,
+						ELF_SHDR *shbuf,
+						struct elf_section *scn_cache)
+{
+	ELF_SHDR* cursct = NULL;
+	char *strtab;
+	int cnt;
+
+	if (scn_cache[ehdr->e_shstrndx].c_data == NULL) {
+	if ((scn_cache[ehdr->e_shstrndx].c_data
+			= read_section_data(fd, ehdr, cursct)) == NULL) {
+				return NULL;
+		}
+	}
+
+	strtab = scn_cache[ehdr->e_shstrndx].c_data;
+
+	for (cursct = shbuf, cnt = 0;
+		cnt < ehdr->e_shnum;
+		cnt++, cursct++) {
+			if (strcmp(cursct->sh_name + strtab, name) == 0) {
+				scn_cache[cnt].c_data = read_section_data(fd, ehdr, cursct);
+				return &scn_cache[cnt];
+			}
+		}
+
+		return NULL;
+}
+
 // read symbol table from given fd.
 struct symtab* build_symtab(int fd) {
   ELF_EHDR ehdr;
@@ -263,7 +295,7 @@ struct symtab* build_symtab(int fd) {
   }
 
 #if defined(ppc64)
-  opd_sect = find_section_by_name(".opd", fd, &ehdr, scn_cache);
+  opd_sect = find_section_by_name(".opd", fd, &ehdr, cursct, scn_cache);
   if (opd_sect != NULL && opd_sect->c_data != NULL && opd_sect->c_shdr != NULL) {
     // plausibility check
     opd = opd_sect->c_shdr;
