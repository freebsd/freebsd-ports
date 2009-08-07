--- generator/qtscript_masterinclude.h.orig	2009-02-20 11:42:24.000000000 +0000
+++ generator/qtscript_masterinclude.h	2009-04-13 08:32:00.000000000 +0000
@@ -31,18 +31,42 @@
 
 #include <QtUiTools/QtUiTools>
 
-#ifndef QT_NO_XMLPATTERNS
-#  include <QtXmlPatterns/QtXmlPatterns>
-#endif
-
-#ifndef QT_NO_WEBKIT
-#  include <QtWebKit/QtWebKit>
-#endif
-
-#ifndef QT_NO_PHONON
-#  include <phonon/phonon>
-#endif
+#include <QtXmlPatterns/QtXmlPatterns>                                                              
 
+#include <QtWebKit/QtWebKit>                                                                        
+                                                                                                    
+#include "phonon/abstractaudiooutput.h"                                                             
+#include "phonon/abstractmediastream.h"                                                             
+#include "phonon/abstractvideooutput.h"                                                             
+#include "phonon/addoninterface.h"                                                                  
+#include "phonon/audiooutput.h"                                                                     
+#include "phonon/audiooutputinterface.h"                                                            
+#include "phonon/backendcapabilities.h"                                                             
+#include "phonon/backendinterface.h"
+#include "phonon/effect.h"
+#include "phonon/effectinterface.h"
+#include "phonon/effectparameter.h"
+#include "phonon/effectwidget.h"
+#include "phonon/mediacontroller.h"
+#include "phonon/medianode.h"
+#include "phonon/mediaobject.h"
+#include "phonon/mediaobjectinterface.h"
+#include "phonon/mediasource.h"
+#include "phonon/objectdescription.h"
+#include "phonon/objectdescriptionmodel.h"
+#include "phonon/path.h"
+#include "phonon/phonondefs.h"
+#include "phonon/phononnamespace.h"
+#include "phonon/platformplugin.h"
+#include "phonon/seekslider.h"
+#include "phonon/streaminterface.h"
+#include "phonon/videoplayer.h"
+#include "phonon/videowidget.h"
+#include "phonon/videowidgetinterface.h"
+#include "phonon/volumefadereffect.h"
+#include "phonon/volumefaderinterface.h"
+#include "phonon/volumeslider.h"
+ 
 #include "../qtbindings/qtscript_core/qtscriptconcurrent.h"
 
 #ifndef QT_NO_OPENGL
