--- sim/ucsim/packages_in.mk.orig	Fri Nov  5 17:23:28 2004
+++ sim/ucsim/packages_in.mk	Fri Nov  5 17:24:26 2004
@@ -37,4 +37,7 @@
 endif
 
 PKGS		= cmd.src sim.src gui.src $(S51) $(SAVR) $(SZ80) $(XA) \
-		  $(SHC08) doc
+		  $(SHC08)
+ifndef NOPORTDOCS
+PKGS		+= doc
+endif
