OpenOffice DOC document Heap Overflow
o http://www.openoffice.org/servlets/ReadMsg?list=releases&msgNo=8387
o http://www.openoffice.org/servlets/ReadMsg?list=releases&msgNo=8417
http://util.openoffice.org/source/browse/util/sot/source/sdstor/stgole.cxx?r1=1.4&r2=1.4.166.1

Index: sot/source/sdstor/stgole.cxx
===================================================================
RCS file: /cvs/util/sot/source/sdstor/stgole.cxx,v
retrieving revision 1.4
diff -u -r1.4 stgole.cxx
--- sot/source/sdstor/stgole.cxx	22 Jul 2002 12:28:43 -0000	1.4
+++ sot/source/sdstor/stgole.cxx	18 Apr 2005 01:34:25 -0000
@@ -156,6 +156,8 @@
 		*this >> aClsId;
 		INT32 nLen1 = 0;
 		*this >> nLen1;
+                // higher bits are ignored
+                nLen1 &= 0xFFFF;
 		sal_Char* p = new sal_Char[ (USHORT) nLen1 ];
 		if( Read( p, nLen1 ) == (ULONG) nLen1 )
 		{
