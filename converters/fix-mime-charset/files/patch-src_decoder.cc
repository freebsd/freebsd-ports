--- src/decoder.cc.orig	2003-08-28 18:45:38 UTC
+++ src/decoder.cc
@@ -1,6 +1,7 @@
 // @(#) $Id: decoder.cc,v 1.7 2003/08/28 18:45:38 balu Exp $
 
 #include "decoder.h"
+#include <cstring>
 
 unsigned char base64_rank[256]=
        {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
