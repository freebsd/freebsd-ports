--- ccgm.c.orig	Mon Oct 12 23:59:40 1992
+++ ccgm.c	Sat Jun 16 03:06:24 2007
@@ -2,9 +2,118 @@
 /* all rights reserved */
 /* module to take care of clear text command processing */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "defs.h"	/* type definitions */
 #include "ccdefs.h"	/* clear text definitions */
 
+static class0();
+static class1();
+static class2();
+static class3();
+static class4();
+static class5();
+static class6();
+static class7();
+static f_b_mf();
+static f_e_mf();
+static f_b_p();
+static f_b_p_body();
+static f_e_pic();
+static rd_mf_version();
+static rd_mf_descriptor();
+static s_vdc_type();
+static s_int_prec();
+static s_real_prec();
+static s_index_prec();
+static s_col_prec();
+static s_cind_prec();
+static s_cvextent();
+static s_mcind();
+static do_mcind();
+static rd_mf_list();
+static s_mf_defs();
+static do_font_list();
+static do_char_list();
+static do_cannounce();
+static s_scalmode();
+static s_c_s_mode();
+static s_lws_mode();
+static s_ms_mode();
+static s_ew_mode();
+static s_vdc_extent();
+static s_back_col();
+static s_vdc_i_p();
+static s_vdc_r_p();
+static s_aux_col();
+static s_transp();
+static s_clip_rec();
+static s_clip_ind();
+static do_polyline();
+static do_dis_polyline();
+static do_polymarker();
+static s_text();
+static s_rex_text();
+static s_app_text();
+static do_polygon();
+static do_polyset();
+static do_cell_array();
+static do_g_d_p();
+static do_rectangle();
+static do_circle();
+static do_c3();
+static do_c3_close();
+static do_c_centre();
+static do_c_c_close();
+static do_ellipse();
+static do_ell_arc();
+static do_e_a_close();
+static s_lbindex();
+static s_l_type();
+static s_l_width();
+static s_l_colour();
+static s_mbindex();
+static s_mk_type();
+static s_mk_size();
+static s_mk_colour();
+static s_tbindex();
+static s_t_index();
+static s_t_prec();
+static s_c_exp();
+static s_c_space();
+static s_t_colour();
+static s_c_height();
+static s_c_orient();
+static s_tpath();
+static s_t_align();
+static s_csindex();
+static s_acsindex();
+static s_fbindex();
+static s_interior_style();
+static s_fill_colour();
+static s_hindex();
+static s_pindex();
+static s_e_b_index();
+static s_edge_t();
+static s_edge_w();
+static s_edge_c();
+static s_edge_v();
+static s_fill_ref();
+static p_tab_entry();
+static s_pat_size();
+static c_tab_entry();
+static do_aspsflags();
+static do_escape();
+static do_message();
+static do_apdata();
+static my_scan_int();
+static get_decimal();
+static get_based();
+static my_scan_float();
+static get_token();
+static cc_same();
+static get_prec();
+
 /* global pointers that use storage from the main program */
 
 static struct 	mf_d_struct 	*glbl1;	/* the class 1 elements */
@@ -62,7 +171,6 @@
      
      /* cgm specific functions */
 #define e_size 2
-     extern char *malloc();			/* for neatness */
 #define intalloc (int *) malloc /* for convenience */
        static char *cc_str();	/* does the necessary translation */
      static float cc_real();	/* does the necessary translation */
@@ -3367,7 +3475,7 @@
      struct ad_struct *this_ad;	/* general address structure */
 {
 static struct ad_struct last_ad;	/* last address */
-  char *my_ptr, c, *realloc(), last_quote = '\"';
+  char *my_ptr, c, last_quote = '\"';
   int p_len, done, new_size;
   enum {normal, quoting, spacing, commenting} my_state;
   
