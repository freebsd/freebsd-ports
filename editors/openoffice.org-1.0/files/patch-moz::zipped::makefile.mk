--- ../moz/zipped/makefile.mk.orig	Tue Jun  4 00:08:23 2002
+++ ../moz/zipped/makefile.mk	Tue Jun  4 00:07:08 2002
@@ -84,6 +84,7 @@
 
 $(MISC)$/unpacked_$(TARGET)_inc : $(OS)$(COM)$(CPU)inc.zip
 	+unzip -o -d $(INCCOM) $(OS)$(COM)$(CPU)inc.zip && $(TOUCH)	$@
+	+cp -r $(INCCOM)/mozilla ../../solver/$(UPD)/$(INPATH)/inc/mozilla
 	+chmod -R 775 $(INCCOM)
 
 .ELSE
