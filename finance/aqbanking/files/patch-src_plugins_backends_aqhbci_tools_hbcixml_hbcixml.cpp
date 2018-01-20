Fix build with clang 6.
hbcixml.cpp:67:37: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
  MYNAME " v1.99  (part of AqHBCI v"AQHBCI_VERSION_STRING")\n"\

--- src/plugins/backends/aqhbci/tools/hbcixml/hbcixml.cpp.orig	2018-01-20 23:43:27 UTC
+++ src/plugins/backends/aqhbci/tools/hbcixml/hbcixml.cpp
@@ -64,7 +64,7 @@ using namespace std;
 
 #define MYNAME "hbcixml2"
 #define PRG_VERSION_INFO \
-  MYNAME " v1.99  (part of AqHBCI v"AQHBCI_VERSION_STRING")\n"\
+  MYNAME " v1.99  (part of AqHBCI v" AQHBCI_VERSION_STRING ")\n"\
   "(c) 2005 Martin Preuss<martin@libchipcard.de>\n" \
   "This program is free software licensed under GPL.\n"\
   "See COPYING for details.\n"
