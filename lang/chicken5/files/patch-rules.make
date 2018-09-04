--- rules.make.orig	2018-09-03 08:22:31 UTC
+++ rules.make
@@ -252,7 +252,7 @@ $(eval $(call declare-program-from-object,$(CSI_STATIC
 
 # "chicken-do"
 
-$(CHICKEN_DO_PROGRAM)$(EXE): $(SRCDIR)chicken-do.c
+$(CHICKEN_DO_PROGRAM)$(EXE): $(SRCDIR)chicken-do.c $(CHICKEN_CONFIG_H)
 	$(C_COMPILER) $(C_COMPILER_OPTIONS) $< -o $@
 
 # scripts
