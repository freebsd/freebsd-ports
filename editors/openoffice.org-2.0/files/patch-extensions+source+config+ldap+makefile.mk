o llber50 is missing
o http://www.openoffice.org/issues/show_bug.cgi?id=43037

Index: makefile.mk
===================================================================
RCS file: /cvs/util/extensions/source/config/ldap/makefile.mk,v
retrieving revision 1.4.24.2
diff -u -u -r1.4.24.2 makefile.mk
--- extensions/source/config/ldap/makefile.mk	27 Jan 2005 19:26:59 -0000	1.4.24.2
+++ extensions/source/config/ldap/makefile.mk	18 Feb 2005 08:21:16 -0000
@@ -114,6 +114,9 @@
         $(SALLIB)
 .IF "$(OS)"=="FREEBSD"
 SHL1STDLIBS+=-lcompat
+.IF "$(WITH_OPENLDAP)" != "YES"
+SHL1STDLIBS+=-llber50
+.ENDIF
 .ENDIF
 
 DEF1NAME=$(SHL1TARGET)
