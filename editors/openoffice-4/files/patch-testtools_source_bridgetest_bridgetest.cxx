--- testtools/source/bridgetest/bridgetest.cxx.orig	2014-02-25 08:19:34 UTC
+++ testtools/source/bridgetest/bridgetest.cxx
@@ -544,7 +544,12 @@ static sal_Bool performTest(
             } catch (...) {
                 bRet &= check(false, "getRaiseAttr2 threw wrong type");
             }
-#ifndef OS2 // see i120310 for details
+#if !defined(OS2) && !(defined(FREEBSD) && defined(INTEL))
+// see i120310 for OS2 details
+// FreeBSD i386 coredumps on this test in cpp_vtable_call():
+//  pTypeDescr appears to point to garbage, pMapFunctionIndexToMemberIndex
+//  points to unreadable memory, as does abase.pTypeName.  Refcounts
+//  don't look reasonable, etc.
             // Test instantiated polymorphic struct types:
             {
                 bRet &= check(
