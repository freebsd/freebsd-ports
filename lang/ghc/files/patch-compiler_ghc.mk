--- ./compiler/ghc.mk.orig	2012-02-01 19:10:32.000000000 +0100
+++ ./compiler/ghc.mk	2012-05-17 11:32:41.868463028 +0200
@@ -107,6 +107,10 @@
 	@echo 'cRAWCPP_FLAGS         = "$(RAWCPP_FLAGS)"'                   >> $@
 	@echo 'cLdHasNoCompactUnwind :: String'                             >> $@
 	@echo 'cLdHasNoCompactUnwind = "$(LdHasNoCompactUnwind)"'           >> $@
+	@echo 'cLdHashSize31 :: String'                                     >> $@
+	@echo 'cLdHashSize31 = "$(LdHashSize31)"'                           >> $@
+	@echo 'cLdReduceMemoryOverheads :: String'                          >> $@
+	@echo 'cLdReduceMemoryOverheads = "$(LdReduceMemoryOverheads)"'     >> $@
 	@echo 'cLdIsGNULd            :: String'                             >> $@
 	@echo 'cLdIsGNULd            = "$(LdIsGNULd)"'                      >> $@
 	@echo 'cLdHasBuildId         :: String'                             >> $@
