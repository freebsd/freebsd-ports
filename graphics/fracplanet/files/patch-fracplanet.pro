--- fracplanet.pro~	2012-05-19 23:50:08.000000000 -0300
+++ fracplanet.pro	2012-05-19 23:50:19.000000000 -0300
@@ -8,7 +8,7 @@
 
 HEADERS += $$system(ls *.h)
 SOURCES += $$system(ls *.cpp)
-LIBS += -lboost_program_options
+LIBS += -lboost_program_options -lGLU
 
 DEFINES += QT_DLL
 
