--- perl.h.orig	2014-10-01 01:33:00 UTC
+++ perl.h
@@ -4254,7 +4254,7 @@ START_EXTERN_C
 EXTCONST char PL_warn_uninit[]
   INIT("Use of uninitialized value%s%s%s");
 EXTCONST char PL_warn_uninit_sv[]
-  INIT("Use of uninitialized value%"SVf"%s%s");
+  INIT("Use of uninitialized value%" SVf "%s%s");
 EXTCONST char PL_warn_nosemi[]
   INIT("Semicolon seems to be missing");
 EXTCONST char PL_warn_reserved[]
@@ -4274,7 +4274,7 @@ EXTCONST char PL_no_usym[]
 EXTCONST char PL_no_aelem[]
   INIT("Modification of non-creatable array value attempted, subscript %d");
 EXTCONST char PL_no_helem_sv[]
-  INIT("Modification of non-creatable hash value attempted, subscript \"%"SVf"\"");
+  INIT("Modification of non-creatable hash value attempted, subscript \"%" SVf "\"");
 EXTCONST char PL_no_modify[]
   INIT("Modification of a read-only value attempted");
 EXTCONST char PL_no_mem[sizeof("Out of memory!\n")]
