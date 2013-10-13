--- tipp10.pro	2011-03-12 20:22:32.000000000 +0100
+++ tipp10.pro	2011-07-24 14:24:03.000000000 +0200
@@ -88,3 +88,5 @@
                     sql/startsql.cpp \
                     games/abcrainwidget.cpp \
                     games/charball.cpp
+
+DEFINES += "DATADIR=\"\\\"$$(DATADIR)\\\"\""
