--- mk_freebsd.mk.orig	2019-12-06 15:03:22 UTC
+++ mk_freebsd.mk
@@ -41,14 +41,14 @@ ALL_S7_LIBS = ../bin/$(COMPILER_LIB) ../bin/$(COMP_DAT
 GET_CC_VERSION_INFO = $(CC) --version >
 
 TERMINFO_OR_TERMCAP = USE_TERMINFO
-CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_inf.o
-CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_inf.c
+# CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_inf.o
+# CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_inf.c
 # TERMINFO_OR_TERMCAP = USE_TERMCAP
 # CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_inf.o trm_cap.o
 # CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_inf.c trm_cap.c
 # TERMINFO_OR_TERMCAP = USE_TERMINFO
-# CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_inf.o
-# CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_inf.c
+CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_inf.o
+CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_inf.c
 # TERMINFO_OR_TERMCAP = USE_TERMCAP
 # CONSOLE_LIB_OBJ = kbd_rtl.o con_inf.o kbd_poll.o trm_cap.o
 # CONSOLE_LIB_SRC = kbd_rtl.c con_inf.c kbd_poll.c trm_cap.c
@@ -84,7 +84,7 @@ DOBJ = big_rtl.o big_gmp.o cmd_unx.o dir_win.o dll_unx
 OBJ = $(MOBJ)
 SEED7_LIB_OBJ = $(ROBJ) $(DOBJ)
 DRAW_LIB_OBJ = gkb_rtl.o drw_x11.o gkb_x11.o fwd_x11.o
-DATABASE_LIB_OBJ = sql_base.o sql_db2.o sql_fire.o sql_lite.o sql_my.o sql_oci.o sql_odbc.o sql_post.o sql_srv.o
+DATABASE_LIB_OBJ = sql_base.o sql_db2.o sql_fire.o sql_lite.o sql_my.o sql_oci.o sql_odbc.o sql_post.o sql_srv.o sql_tds.o
 COMP_DATA_LIB_OBJ = typ_data.o rfl_data.o ref_data.o listutl.o flistutl.o typeutl.o datautl.o
 COMPILER_LIB_OBJ = $(POBJ) $(LOBJ) $(EOBJ) $(AOBJ) $(GOBJ)
 
@@ -168,6 +168,7 @@ chkccomp.h:
 	echo "#define POSTGRESQL_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
 	echo "#define ODBC_INCLUDE_OPTIONS \"-I%%LOCALBASE%%/include\"" >> chkccomp.h
 	echo "#define ODBC_LIBRARY_PATH \"-L%%LOCALBASE%%/lib\"" >> chkccomp.h
+	echo "#define X11_LIBRARY_PATH \"%%LOCALBASE%%/lib\"" >> chkccomp.h
 
 version.h: chkccomp.h
 	echo "#define PATH_DELIMITER '/'" > version.h
