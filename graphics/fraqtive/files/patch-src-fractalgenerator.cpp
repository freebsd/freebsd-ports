--- src/fractalgenerator.cpp	2008/04/04 15:29:05	11
+++ src/fractalgenerator.cpp	2008/04/05 15:09:39	12
@@ -182,6 +182,8 @@
             break;
 
         case PartialUpdate:
+            if ( data->isEmpty() )
+                return NoUpdate;
             data->setValidRegions( m_validRegions );
             break;
 
