--- mk_freebsd.mk.orig	2020-01-14 12:29:39 UTC
+++ mk_freebsd.mk
@@ -41,14 +41,14 @@ ALL_S7_LIBS = ../bin/$(COMPILER_LIB) ../bin/$(COMP_DAT
 GET_CC_VERSION_INFO = $(CC) --version >
 
 TERMINFO_OR_TERMCAP = USE_TERMINFO
+# CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_inf.o
+# CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_inf.c
-CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_inf.o
-CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_inf.c
 # TERMINFO_OR_TERMCAP = USE_TERMCAP
 # CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_cap.o
 # CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_cap.c
 # TERMINFO_OR_TERMCAP = USE_TERMINFO
+CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_inf.o
+CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_inf.c
-# CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_inf.o
-# CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_inf.c
 # TERMINFO_OR_TERMCAP = USE_TERMCAP
 # CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_cap.o
 # CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_cap.c
@@ -168,6 +168,7 @@ chkccomp.h:
 	echo "#define POSTGRESQL_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
 	echo "#define ODBC_INCLUDE_OPTIONS \"-I%%LOCALBASE%%/include\"" >> chkccomp.h
 	echo "#define ODBC_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
+	echo "#define X11_LIBRARY_PATH \"%%LOCALBASE%%/lib\"" >> chkccomp.h
 
 version.h: chkccomp.h
 	echo "#define PATH_DELIMITER '/'" > version.h
