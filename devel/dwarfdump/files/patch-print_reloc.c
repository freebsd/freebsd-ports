--- print_reloc.c.orig	2008-08-30 21:13:43.000000000 -0500
+++ print_reloc.c	2008-08-30 21:18:48.000000000 -0500
@@ -409,7 +409,7 @@
            }
         } else if (sym_data_64) {
            size_t index = ELF64_R_SYM(p->r_info) - 1;
-           if(index < sym_data_entry_count) {
+           if(index < sym_data_64_entry_count) {
               name = sym_data_64[index].name;
            }
         }
