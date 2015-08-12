--- src/database/threadedguess.cpp.orig	2015-04-28 18:00:47 UTC
+++ src/database/threadedguess.cpp
@@ -2,6 +2,7 @@
 *   Copyright (C) 2014 by Jens Nissen jens-chessx@gmx.net                   *
 ****************************************************************************/
 
+#include <QMetaType>
 #include "threadedguess.h"
 #include "guess.h"
 
