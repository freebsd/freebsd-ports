--- src/elfhacks.cpp.orig	2020-08-16 16:54:20 UTC
+++ src/elfhacks.cpp
@@ -195,22 +195,22 @@ int eh_init_obj(eh_obj_t *obj)
 			if (obj->strtab)
 				return ENOTSUP;
 
-			obj->strtab = (const char *) obj->dynamic[p].d_un.d_ptr;
+			obj->strtab = (const char *) (obj->dynamic[p].d_un.d_ptr + obj->addr);
 		} else if (obj->dynamic[p].d_tag == DT_HASH) {
 			if (obj->hash)
 				return ENOTSUP;
 
-			obj->hash = (ElfW(Word) *) obj->dynamic[p].d_un.d_ptr;
+			obj->hash = (ElfW(Word) *) (obj->dynamic[p].d_un.d_ptr + obj->addr);
 		} else if (obj->dynamic[p].d_tag == DT_GNU_HASH) {
 			if (obj->gnu_hash)
 				return ENOTSUP;
 
-			obj->gnu_hash = (Elf32_Word *) obj->dynamic[p].d_un.d_ptr;
+			obj->gnu_hash = (Elf32_Word *) (obj->dynamic[p].d_un.d_ptr + obj->addr);
 		} else if (obj->dynamic[p].d_tag == DT_SYMTAB) {
 			if (obj->symtab)
 				return ENOTSUP;
 
-			obj->symtab = (ElfW(Sym) *) obj->dynamic[p].d_un.d_ptr;
+			obj->symtab = (ElfW(Sym) *) (obj->dynamic[p].d_un.d_ptr + obj->addr);
 		}
 		p++;
 	}
