--- Make-default.mk.orig	2010-10-17 19:26:58.000000000 +0200
+++ Make-default.mk	2010-10-17 19:27:26.000000000 +0200
@@ -134,7 +134,7 @@
 endif
 
 .depend:
-	$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
+	#$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
 
 dep:	.depend
 
