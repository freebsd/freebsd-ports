--- mk/beforedir.mk.orig	Wed Mar 14 12:29:06 2001
+++ mk/beforedir.mk	Wed Mar 14 12:29:37 2001
@@ -313,7 +313,7 @@
 
 CORBA_IDL_FILES = $(CORBA_INTERFACES:%=%.idl)
 
-CORBA_STUB_DIR = $(TOP)/stub
+CORBA_STUB_DIR = $(TOP)/idl
 
 CorbaImplementation = NO_CORBA_IMPLEMENTATION
 
