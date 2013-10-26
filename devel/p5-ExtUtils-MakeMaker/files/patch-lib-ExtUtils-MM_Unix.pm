ExtUtils::MakeMaker starting from 6.80 by default does not copy .bs files if they are empty.
More information can be obtained from ports/183305

--- lib/ExtUtils/MM_Unix.pm.orig	2013-10-15 23:04:44.000000000 +0800
+++ lib/ExtUtils/MM_Unix.pm	2013-10-26 04:30:48.748262789 +0800
@@ -958,8 +958,8 @@
 
     push @m, <<'MAKE';
 	$(CHMOD) $(PERM_RWX) $@
-	$(NOECHO) $(RM_RF) $(BOOTSTRAP)
-	- $(CP_NONEMPTY) $(BOOTSTRAP) $(INST_BOOT) $(PERM_RW)
+	$(NOECHO) $(RM_RF) $(INST_BOOT)
+	- $(TOUCH) $(BOOTSTRAP) && $(CP) $(BOOTSTRAP) $(INST_BOOT) && $(CHMOD) $(PERM_RW) $(INST_BOOT)
 MAKE
 
     return join('',@m);
