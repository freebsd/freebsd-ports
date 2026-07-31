--- src/3rdParty/salomesmesh/inc/SMESH_TryCatch.hxx.orig	2026-04-14 22:09:59 UTC
+++ src/3rdParty/salomesmesh/inc/SMESH_TryCatch.hxx
@@ -65,11 +65,45 @@
 // Two onExceptionFun() are defined here: SMESH::throwSalomeEx() and SMESH::doNothing().
 // To add your own catch close, define SMY_OWN_CATCH macro before including this file.
 
+#include <Standard_Version.hxx>
+#if OCC_VERSION_HEX >= 0x080000
 #define SMESH_CATCH( onExceptionFun )                                   \
   }                                                                     \
   catch (Standard_Failure& ex)                                          \
   {                                                                     \
     SMESH_Comment text("OCCT Exception: ");                             \
+    text << ": " << ex.ExceptionType();                                 \
+    if ( ex.what() && strlen( ex.what() ))                              \
+      text << ": " << ex.what();                                        \
+    SMESH_CAUGHT onExceptionFun( text );                                \
+  }                                                                     \
+  catch ( ::SMESH_ComputeError& ce )                                    \
+  {                                                                     \
+    if ( !ce.myComment.empty() )                                        \
+      SMESH_CAUGHT onExceptionFun( ce.myComment.c_str() );              \
+    else if ( ce.IsCommon() )                                           \
+      SMESH_CAUGHT onExceptionFun( ce.CommonName().c_str() );           \
+    else                                                                \
+      SMESH_CAUGHT onExceptionFun                                       \
+        (SMESH_Comment("SMESH_ComputeError: ") << ce.myName );          \
+  }                                                                     \
+  catch ( const std::exception& ex)                                     \
+  {                                                                     \
+    SMESH_CAUGHT onExceptionFun( ex.what() );                           \
+  }                                                                     \
+                                                                        \
+  SMY_OWN_CATCH                                                         \
+                                                                        \
+  catch (...)                                                           \
+  {                                                                     \
+    SMESH_CAUGHT onExceptionFun("Unknown Exception caught");            \
+  }
+#else
+#define SMESH_CATCH( onExceptionFun )                                   \
+  }                                                                     \
+  catch (Standard_Failure& ex)                                          \
+  {                                                                     \
+    SMESH_Comment text("OCCT Exception: ");                             \
     text << ": " << ex.DynamicType()->Name();                           \
     if ( ex.GetMessageString() && strlen( ex.GetMessageString() ))      \
       text << ": " << ex.GetMessageString();                            \
@@ -96,6 +131,7 @@
   {                                                                     \
     SMESH_CAUGHT onExceptionFun("Unknown Exception caught");            \
   }
+#endif
 
 //-------------------------------------------------------------------------------------
 // Functions that can be used as an argument of SMESH_CATCH
