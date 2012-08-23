--- ./dbaccess/source/core/api/TableDeco.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./dbaccess/source/core/api/TableDeco.cxx	2012-07-18 14:52:59.000000000 -0400
@@ -172,7 +172,7 @@
             {
                 Any aValue;
                 getFastPropertyValue(aValue,nHandle);
-                bRet = ::comphelper::tryPropertyValue(rConvertedValue,rOldValue,rValue,aValue,::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+                bRet = ::comphelper::tryPropertyValue(rConvertedValue,rOldValue,rValue,aValue,::getCppuType(static_cast< ::rtl::OUString*>(0)));
             }
             break; // we assume that it works
     }
