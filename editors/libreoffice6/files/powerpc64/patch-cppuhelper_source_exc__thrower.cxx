--- cppuhelper/source/exc_thrower.cxx.orig	2020-11-27 22:07:39 UTC
+++ cppuhelper/source/exc_thrower.cxx
@@ -220,6 +220,7 @@ namespace cppu
 {
 
 
+__attribute__ ((optnone))
 void SAL_CALL throwException( Any const & exc )
 {
     if (exc.getValueTypeClass() != TypeClass_EXCEPTION)
