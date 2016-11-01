--- Make-default.mk.orig	2013-01-12 14:25:08 UTC
+++ Make-default.mk
@@ -134,7 +134,7 @@ include .depend
 endif
 
 .depend:
-	$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
+	#$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
 
 dep:	.depend
 
