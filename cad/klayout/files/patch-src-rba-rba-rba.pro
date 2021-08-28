--- src/rba/rba/rba.pro.orig	2021-08-28 16:13:08 UTC
+++ src/rba/rba/rba.pro
@@ -25,5 +25,5 @@ HEADERS += \
 # NOTE: ../common needs to be before RUBYINCLUDE since there is a config.h too.
 INCLUDEPATH += ../common "$$RUBYINCLUDE" "$$RUBYINCLUDE2" $$TL_INC $$GSI_INC
 DEPENDPATH += ../common "$$RUBYINCLUDE" "$$RUBYINCLUDE2" $$TL_INC $$GSI_INC
-LIBS += "$$RUBYLIBFILE" -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += "$$RUBYLIBFILE" $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
   
