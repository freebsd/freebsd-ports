--- plasma/lib/fileformat/elf.py.orig	2019-02-27 16:23:45 UTC
+++ plasma/lib/fileformat/elf.py
@@ -215,9 +215,13 @@ class ELF(Binary):
         # pyreadelf's assumptions make our own string table
         fakestrtabheader = {
             "sh_offset": self.__get_offset(self.dtags["DT_STRTAB"]),
+            "sh_size":0,
+            "sh_flags":0,
+            "sh_addralign":0
         }
+
         strtab = StringTableSection(
-                fakestrtabheader, "strtab_plasma", self.elf.stream)
+                fakestrtabheader, "strtab_plasma", self.elf)
 
         # ...
         # Here in CLE was checked the DT_SONAME 
@@ -232,7 +236,9 @@ class ELF(Binary):
         fakesymtabheader = {
             "sh_offset": self.__get_offset(self.dtags["DT_SYMTAB"]),
             "sh_entsize": self.dtags["DT_SYMENT"],
-            "sh_size": 0
+            "sh_size": 0,
+            "sh_flags": 0,
+            "sh_addralign" : 0
         } # bogus size: no iteration allowed
 
         # ...
@@ -240,7 +246,7 @@ class ELF(Binary):
         # ...
 
         self.dynsym = SymbolTableSection(
-                fakesymtabheader, "symtab_plasma", self.elf.stream,
+                fakesymtabheader, "symtab_plasma",
                 self.elf, strtab)
 
         # mips' relocations are absolutely screwed up, handle some of them here.
@@ -276,11 +282,12 @@ class ELF(Binary):
                 "sh_offset": self.__get_offset(reloffset),
                 "sh_type": "SHT_" + rela_type,
                 "sh_entsize": relentsz,
-                "sh_size": relsz
+                "sh_size": relsz,
+                "sh_flags":0,
+                "sh_addralign":0
             }
             reloc_sec = RelocationSection(
-                    fakerelheader, "reloc_plasma",
-                    self.elf.stream, self.elf)
+                    fakerelheader, "reloc_plasma", self.elf)
             self.__register_relocs(reloc_sec)
 
         # try to parse relocations out of a table of type DT_JMPREL
@@ -291,11 +298,13 @@ class ELF(Binary):
                 "sh_offset": self.__get_offset(jmpreloffset),
                 "sh_type": "SHT_" + rela_type,
                 "sh_entsize": relentsz,
-                "sh_size": jmprelsz
+                "sh_size": jmprelsz,
+                "sh_flags":0,
+                "sh_addralign":0
             }
             jmprel_sec = RelocationSection(
                     fakejmprelheader, "jmprel_plasma",
-                    self.elf.stream, self.elf)
+                    self.elf)
 
             self.jmprel = self.__register_relocs(jmprel_sec)
 
