o llber50 is missing
o http://www.openoffice.org/issues/show_bug.cgi?id=43037

Index: extensions/source/config/ldap/makefile.mk
===================================================================
RCS file: /cvs/util/extensions/source/config/ldap/makefile.mk,v
retrieving revision 1.5
diff -u -r1.5 makefile.mk
--- extensions/source/config/ldap/makefile.mk	18 Jan 2005 15:18:56 -0000	1.5
+++ extensions/source/config/ldap/makefile.mk	17 Feb 2005 23:21:16 -0000
@@ -117,7 +117,7 @@
         $(SALHELPERLIB) \
         $(SALLIB)
 .IF "$(OS)"=="FREEBSD"
-SHL1STDLIBS+=-lcompat
+SHL1STDLIBS+=-lcompat -llber50
 .ENDIF
 
 DEF1NAME=$(SHL1TARGET)
