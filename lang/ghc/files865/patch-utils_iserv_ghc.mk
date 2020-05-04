--- utils/iserv/ghc.mk.orig	2020-03-23 22:25:01 UTC
+++ utils/iserv/ghc.mk
@@ -31,7 +31,7 @@ endif
 # of overhead to startup and increases the binary sizes) but if you
 # need it there's no alternative.
 ifeq "$(TargetElf)" "YES"
-ifneq "$(TargetOS_CPP)" "solaris2"
+ifeq "$(findstring $(TargetOS_CPP), solaris2 freebsd)" ""
 # The Solaris linker does not support --export-dynamic option. It also
 # does not need it since it exports all dynamic symbols by default
 utils/iserv_stage2_MORE_HC_OPTS += -optl-Wl,--export-dynamic
