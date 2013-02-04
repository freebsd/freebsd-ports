--- xchomp.h.orig
+++ xchomp.h
@@ -6,6 +6,7 @@
 #include <signal.h>
 #include <setjmp.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -74,7 +75,7 @@
 typedef int		intm[8];
 typedef char		charm[BLOCK_WIDTH];
 typedef charm		mazedata[BLOCK_HEIGHT];
-typedef int		(*funcptr)();
+typedef void		(*funcptr)();
 
 EXTERN Atom		DEC_icon_atom;
 
@@ -136,6 +137,44 @@
 
 EXTERN jmp_buf		jb_start;
 
-extern			follow(), hover(), hover2(), run(), go_home();
-extern			die(), eat(), noop();
-extern Bool		pause_seq();
+EXTERN void		follow(int);
+EXTERN void		run(int);
+EXTERN void		go_home(int);
+EXTERN void		hover(int);
+EXTERN void		hover2(int);
+EXTERN void		die(int);
+EXTERN void		eat(int);
+EXTERN void		noop(int);
+EXTERN Bool		pause_seq();
+
+void do_exit();  
+void play_game(int);
+void destroy_regions();
+void create_ghost();
+void create_pac();  
+void create_fruit();
+void create_maze_symbols();
+void create_demo_images();
+void create_GCs();
+void create_window(int, char **);
+void create_maps();   
+void create_regions();
+void demo_seq();
+void display_title();    
+void print_score(long);  
+void display_level(Bool);
+void clear_maps();  
+void read_maze(int);
+void position_players();
+int set_lives(int);
+void get_ready();
+void restore_status();
+void control_pac();
+void usleep(int);  
+void do_sleep(int);
+void do_usleep(int);
+void game_over();
+void finish();
+void control_pac();
+void check_dots();
+void check_normal_events();
