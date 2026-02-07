--- output/outelf.c.orig	2020-07-02 04:44:07 UTC
+++ output/outelf.c
@@ -248,7 +248,7 @@ static int32_t elf_gotpc_sect, elf_gotoff_sect;
 static int32_t elf_got_sect, elf_plt_sect;
 static int32_t elf_sym_sect, elf_gottpoff_sect, elf_tlsie_sect;
 
-uint8_t elf_osabi = 0;      /* Default OSABI = 0 (System V or Linux) */
+uint8_t elf_osabi = 9;      /* Default OSABI = 9 (FreeBSD) */
 uint8_t elf_abiver = 0;     /* Current ABI version */
 
 /* Known sections with nonstandard defaults. -n means n*pointer size. */
