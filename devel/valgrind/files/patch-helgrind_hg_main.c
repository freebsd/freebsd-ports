===================================================================
RCS file: /home2/webcvs/mirror/valgrind/helgrind/hg_main.c,v
retrieving revision 1.60.2.3
retrieving revision 1.60.2.4
diff -u -p -r1.60.2.3 -r1.60.2.4
--- helgrind/hg_main.c	2003/12/01 13:11:15	1.60.2.3
+++ helgrind/hg_main.c	2004/02/29 15:53:40	1.60.2.4
@@ -3101,42 +3101,42 @@ static void eraser_mem_write(Addr a, UIn
 
 #undef DEBUG_STATE
 
-static void eraser_mem_help_read_1(Addr a)
+REGPARM(1) static void eraser_mem_help_read_1(Addr a)
 {
    eraser_mem_read(a, 1, VG_(get_current_tid)());
 }
 
-static void eraser_mem_help_read_2(Addr a)
+REGPARM(1) static void eraser_mem_help_read_2(Addr a)
 {
    eraser_mem_read(a, 2, VG_(get_current_tid)());
 }
 
-static void eraser_mem_help_read_4(Addr a)
+REGPARM(1) static void eraser_mem_help_read_4(Addr a)
 {
    eraser_mem_read(a, 4, VG_(get_current_tid)());
 }
 
-static void eraser_mem_help_read_N(Addr a, UInt size)
+REGPARM(2) static void eraser_mem_help_read_N(Addr a, UInt size)
 {
    eraser_mem_read(a, size, VG_(get_current_tid)());
 }
 
-static void eraser_mem_help_write_1(Addr a, UInt val)
+REGPARM(2) static void eraser_mem_help_write_1(Addr a, UInt val)
 {
    if (*(UChar *)a != val)
       eraser_mem_write(a, 1, VG_(get_current_tid)());
 }
-static void eraser_mem_help_write_2(Addr a, UInt val)
+REGPARM(2) static void eraser_mem_help_write_2(Addr a, UInt val)
 {
    if (*(UShort *)a != val)
       eraser_mem_write(a, 2, VG_(get_current_tid)());
 }
-static void eraser_mem_help_write_4(Addr a, UInt val)
+REGPARM(2) static void eraser_mem_help_write_4(Addr a, UInt val)
 {
    if (*(UInt *)a != val)
       eraser_mem_write(a, 4, VG_(get_current_tid)());
 }
-static void eraser_mem_help_write_N(Addr a, UInt size)
+REGPARM(2) static void eraser_mem_help_write_N(Addr a, UInt size)
 {
    eraser_mem_write(a, size, VG_(get_current_tid)());
 }
