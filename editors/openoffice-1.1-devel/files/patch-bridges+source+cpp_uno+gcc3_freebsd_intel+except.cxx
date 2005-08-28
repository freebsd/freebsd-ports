Issutracker : #i22253#
CWS         : N/A
Author      : <mrauch@openoffice.org> (JCA)
Description :

Index: bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx,v
retrieving revision 1.4
diff -u -r1.4 except.cxx
--- bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx	28 Apr 2003 16:41:25 -0000	1.4
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx	13 Aug 2005 04:40:14 -0000
@@ -182,7 +182,7 @@
         buf.append( 'E' );
 
         OString symName( buf.makeStringAndClear() );
-        rtti = (type_info *)dlsym( m_hApp, symName.getStr() );
+        rtti = (type_info *)dlsym( RTLD_DEFAULT,  symName.getStr() );
 
         if (rtti)
         {
