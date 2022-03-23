--- src/Libraries/3D/Source/interp.c.orig	2022-03-23 14:33:24 UTC
+++ src/Libraries/3D/Source/interp.c
@@ -82,7 +82,7 @@ along with this program.  If not, see <http://www.gnu.
 #include "lg.h"
 //#include <String.h>
 //#include <_stdarg.h>
-#include <stdarg.h>
+//#include <stdarg.h>
 
 // prototypes;
 uchar *do_eof(uchar *);
@@ -133,20 +133,9 @@ extern void g3_light_obj(g3s_phandle norm, g3s_phandle
 
 void interpreter_loop(uchar *object);
 
-void FlipVector(short n, g3s_vector *vec);
-void FlipLong(long *lng);
-void FlipShort(short *sh);
-
 // globals
 extern char gour_flag; // gour flag for actual polygon drawer
 
-// clang-format off
-#ifdef stereo_on
-  temp_vector      g3s_vector     <>
-  tmp_address      dd             ?
-#endif
-// clang-format on
-
 #define OP_EOF 0
 #define OP_JNORM 1
 
@@ -194,7 +183,7 @@ grs_bitmap *_vtext_tab[N_VTEXT_ENTRIES] = {
 // clang-format on
 
 // ptr to stack parms
-va_list parm_ptr;
+ubyte *parm_ptr; //va_list parm_ptr;
 
 // space for parms to objects
 char parm_data[PARM_DATA_SIZE];
@@ -205,28 +194,9 @@ char _itrp_check_flg = 0;
 
 // MLA not used, - uchar 	*struct_ptr;
 
-/*
-// process the next opcode
-next	macro	opsize
-        ifnb	<opsize>
-         add	ebp,opsize	// point at next opcode
-        endif
-        jmp	interpreter_loop
-        endm
-
-call_next	macro
-        call	interpreter_loop
-        endm
-*/
-
 // c callable context setting routines
-// set virtual color eax to ebx
-// inlined in 3d.h for now....
-// g3_setvcolor:
-//       add     eax, _vcolor_tab
-//       mov     byte ptr [eax], bl
 
-// takes ptr to object in eax. trashes all but ebp
+// takes ptr to object
 // this is bullshit, man, takes ptr to object on the freakin' stack!
 void g3_interpret_object(ubyte *object_ptr, ...) {
     int i, scale;
@@ -242,100 +212,13 @@ void g3_interpret_object(ubyte *object_ptr, ...) {
             opcode_table[OP_JNORM] = &do_ljnorm;
     }
 
-// clang-format off
-#ifdef stereo_on
-  test    _g3d_stereo,1
-  jz      g3_interpret_object_raw
-  //       call normally if eyesep/distance is small enough (angular change is small)
-  //       transform 0,0,0 to get the z distance
-  mov     eax,_view_position.x
-  fixmul  view_matrix.m3
-  mov     ecx,eax
+    // get addr of stack parms
+    parm_ptr = (&object_ptr) + sizeof(object_ptr); //va_start(parm_ptr, object_ptr);
 
-  mov     eax,_view_position.y
-  fixmul  view_matrix.m6
-  add     ecx,eax
-
-  mov     eax,_view_position.z
-  fixmul  view_matrix.m9
-  add     ecx,eax
-  neg     ecx
-
-  mov     eax,_g3d_eyesep_raw
-  fixmul  _matrix_scale.z
-  fixdiv  ecx
-
-  cmp     eax,STEREO_DIST_LIM
-  jl      g3_interpret_object_raw
-
-  mov     _g3d_stereo,0    // kill stereo
-  pop     eax     // grab real return address
-  mov     tmp_address,eax         // save it for later
-
-  push    ret1    // fake out the poor thing so it jumps back here
-  jmp  g3_interpret_object_raw
-
-  // shift view_position
-  ret1:
-  // save the current position
-  lea     edi,temp_vector
-  lea     esi,_view_position
-  movsd
-  movsd
-  movsd
-
-  mov     eax,_g3d_eyesep_raw
-  mov     ebx,_matrix_scale.x
-  fixdiv  ebx     // make ebx the scaled down eyesep
-  mov     ebx,eax
-
-  // get x slewed over (top row of current vector and scale)
-  mov     eax,view_matrix.m1
-  fixmul  ebx
-  add     _view_position.x,eax
-
-  mov     eax,view_matrix.m4
-  fixmul  ebx
-  add     _view_position.y,eax
-
-  mov     eax,view_matrix.m7
-  fixmul  ebx
-  add     _view_position.z,eax
-
-  set_rt_canv             // install rt canvas
-  // this time when you call it, its still all set
-  call    g3_interpret_object_raw
-  mov     _g3d_stereo,1    // restore stereo
-  set_lt_canv             // restore left canvas
-
-  // restore view position
-  lea     esi,temp_vector
-  lea     edi,_view_position
-  movsd
-  movsd
-  movsd
-
-  // weeee, pretend we were here all along, but I suppose we
-  // could just jmp there
-  push    tmp_address
-
-  ret
-g3_interpret_object_raw:
-#endif
-        // clang-format on
-
-        va_start(parm_ptr, object_ptr); // get addr of stack parms
-
-    // MLA- not used ever?
-    /*
-            mov	eax,16[esp]	// get angle
-            mov	struct_ptr,eax*/
-
     // mark res points as free
     LG_memset(resbuf, 0, N_RES_POINTS * 4);
 
     // scale view vector for scale
-    FlipShort((short *)(object_ptr - 2));
     scale = *(short *)(object_ptr - 2);
     if (scale) {
         if (scale > 0) {
@@ -383,7 +266,6 @@ g3_interpret_object_raw:
 // interpret the object
 void interpreter_loop(uchar *object) {
     do {
-        FlipShort((short *)object);
         object = ((uchar * (*)(uchar *)) opcode_table[*(short *)object])(object);
     } while (object);
 }
@@ -400,9 +282,6 @@ uchar *do_eof(uchar *opcode) // and return extra level
 // v=viewer coords-p
 // if (n*v)<0 then branch to lbl
 uchar *do_jnorm(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipVector(2, (g3s_vector *)(opcode + 4));
-
     if (g3_check_normal_facing((g3s_vector *)(opcode + 16), (g3s_vector *)(opcode + 4)))
         return opcode + 28; // surface is visible. continue
     else
@@ -411,9 +290,6 @@ uchar *do_jnorm(uchar *opcode) {
 
 // lnres pnt0,pnt1
 uchar *do_lnres(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     g3_draw_line(resbuf[*(unsigned short *)(opcode + 2)], resbuf[*(unsigned short *)(opcode + 4)]);
     return opcode + 6;
 }
@@ -421,14 +297,10 @@ uchar *do_lnres(uchar *opcode) {
 uchar *do_multires(uchar *opcode) {
     short count;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     count = *(short *)(opcode + 2);
-    FlipVector(count, (g3s_vector *)(opcode + 6));
 
     g3_transform_list(count, (g3s_phandle *)(resbuf + (*(short *)(opcode + 4))), (g3s_vector *)(opcode + 6));
-    return opcode + 6 + (count * 12); // fixup: ebp = esi + ecx*12
+    return opcode + 6 + (count * 12);
 }
 
 // this should do some cute matrix transform trick, not this ugly hack
@@ -459,68 +331,22 @@ uchar *do_scaleres(uchar *opcode) {
 
             return opcode;
              */
-    /*
-           movzx	ecx,w 2[ebp]	// get count
-           movzx	eax,w 4[ebp]	// get scale factor
-           movzx	ebx,w 6[ebp]	// get dest start num
-           mov     eax,d parm_data [eax]
-           add     ebp,8
-   //	lea	esi,[ebp]	// get vector array start
-   do_sr_loop:
-           push    eax
-           push    ecx
-           push    ebx
-           mov     ecx, eax
-           mov     esi, OFFSET temp_pnt
-   // do better scaling here.....
-           imul    d [ebp]
-           shrd    eax,edx,16
-           mov     [esi],eax
-           mov     eax, ecx
-           imul    d 4[ebp]
-           shrd    eax,edx,16
-           mov     4[esi],eax
-           mov     eax, ecx
-           imul    d 8[ebp]
-           shrd    eax,edx,16
-           mov     8[esi],eax
-           call    g3_transform_point
-           pop     ebx
-           mov     resbuf[ebx*4],edi
-           inc     ebx
-           add     ebp,12
-           lea     esi,[ebp]
-           pop     ecx
-           pop     eax
-           dec     ecx
-           jnz     do_sr_loop
-           next
-    */
     return 0;
 }
 
 // these put the address of an old point in the interpreter respnt array
 // note they will get freed when the interpreter punts
 uchar *do_vpnt_p(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     resbuf[*(short *)(opcode + 4)] = (g3s_point *)(*(long *)(parm_data + (*(unsigned short *)(opcode + 2))));
     return opcode + 6;
 }
 
 uchar *do_vpnt_v(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     resbuf[*(short *)(opcode + 4)] = _vpoint_tab[(*(unsigned short *)(opcode + 2)) >> 2];
     return opcode + 6;
 }
 
 uchar *do_defres(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipVector(1, (g3s_vector *)(opcode + 4));
-
     resbuf[*(unsigned short *)(opcode + 2)] = g3_transform_point((g3s_vector *)(opcode + 4));
     return opcode + 16;
 }
@@ -528,10 +354,6 @@ uchar *do_defres(uchar *opcode) {
 uchar *do_defres_i(uchar *opcode) {
     g3s_phandle temphand;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 16));
-    FlipVector(1, (g3s_vector *)(opcode + 4));
-
     temphand = g3_transform_point((g3s_vector *)(opcode + 4));
     resbuf[*(unsigned short *)(opcode + 2)] = temphand;
 
@@ -545,13 +367,9 @@ uchar *do_defres_i(uchar *opcode) {
 uchar *do_polyres(uchar *opcode) {
     int count, count2;
 
-    FlipShort((short *)(opcode + 2));
-
     count2 = count = *(unsigned short *)(opcode + 2);
     opcode += 4;
     while (--count >= 0) {
-        FlipShort((short *)(opcode + (count << 1)));
-
         poly_buf[count] = resbuf[*(unsigned short *)(opcode + (count << 1))];
     }
 
@@ -567,10 +385,6 @@ uchar *do_polyres(uchar *opcode) {
 }
 
 uchar *do_sortnorm(uchar *opcode) {
-    FlipVector(2, (g3s_vector *)(opcode + 2));
-    FlipShort((short *)(opcode + 26));
-    FlipShort((short *)(opcode + 28));
-
     if (g3_check_normal_facing((g3s_vector *)(opcode + 14), (g3s_vector *)(opcode + 2))) {
         interpreter_loop(opcode + (*(short *)(opcode + 26)));
         interpreter_loop(opcode + (*(short *)(opcode + 28)));
@@ -583,25 +397,18 @@ uchar *do_sortnorm(uchar *opcode) {
 }
 
 uchar *do_goursurf(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     gouraud_base = (*(short *)(opcode + 2)) << 8;
     _itrp_gour_flg = 2;
     return opcode + 4;
 }
 
 uchar *do_gour_p(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     gouraud_base = parm_data[(*(short *)(opcode + 2))] << 8;
     _itrp_gour_flg = 2;
     return opcode + 4;
 }
 
 uchar *do_gour_vc(uchar *opcode) {
-
-    FlipShort((short *)(opcode + 2));
-
     gouraud_base = ((long)_vcolor_tab[*(unsigned short *)(opcode + 2)]) << 8;
     _itrp_gour_flg = 2;
     return opcode + 4;
@@ -610,8 +417,6 @@ uchar *do_gour_vc(uchar *opcode) {
 uchar *do_draw_mode(uchar *opcode) {
     short flags;
 
-    FlipShort((short *)(opcode + 2));
-
     flags = *(short *)(opcode + 2);
     _itrp_wire_flg = flags >> 8;
     flags &= 0x00ff;
@@ -628,15 +433,10 @@ uchar *do_setshade(uchar *opcode) {
     uchar *new_opcode;
     g3s_phandle temphand;
 
-    FlipShort((short *)(opcode + 2));
-
     i = *(unsigned short *)(opcode + 2); // get number of shades
     new_opcode = opcode + 4 + (i << 2);
 
     while (--i >= 0) {
-        FlipShort((short *)(opcode + 4 + (i << 2)));
-        FlipShort((short *)(opcode + 6 + (i << 2)));
-
         temphand = resbuf[*(unsigned short *)(opcode + 4 + (i << 2))]; // get point handle
         temphand->i = *(short *)(opcode + 6 + (i << 2));
         temphand->p3_flags |= PF_I;
@@ -650,14 +450,9 @@ uchar *do_rgbshades(uchar *opcode) {
     int i;
     g3s_phandle temphand;
 
-    FlipShort((short *)(opcode + 2));
-
     i = *(unsigned short *)(opcode + 2); // get number of shades
     new_opcode = opcode + 4;
     while (--i >= 0) {
-        FlipShort((short *)new_opcode);
-        FlipLong((long *)(new_opcode + 2));
-
         temphand = resbuf[*(unsigned short *)new_opcode]; // get point handle
         temphand->rgb = *(long *)(new_opcode + 2);
         temphand->p3_flags |= PF_RGB;
@@ -669,10 +464,6 @@ uchar *do_rgbshades(uchar *opcode) {
 uchar *do_setuv(uchar *opcode) {
     g3s_phandle temphand;
 
-    FlipShort((short *)(opcode + 2));
-    FlipLong((long *)(opcode + 4));
-    FlipLong((long *)(opcode + 8));
-
     temphand = resbuf[*(unsigned short *)(opcode + 2)]; // get point handle
     temphand->uv.u = (*(unsigned long *)(opcode + 4)) >> 8;
     temphand->uv.v = (*(unsigned long *)(opcode + 8)) >> 8;
@@ -685,15 +476,9 @@ uchar *do_uvlist(uchar *opcode) {
     int i;
     g3s_phandle temphand;
 
-    FlipShort((short *)(opcode + 2));
-
     i = *(unsigned short *)(opcode + 2); // get number of shades
     opcode += 4;
     while (--i >= 0) {
-        FlipShort((short *)opcode);
-        FlipLong((long *)(opcode + 2));
-        FlipLong((long *)(opcode + 6));
-
         temphand = resbuf[*(unsigned short *)opcode]; // get point handle
         temphand->uv.u = (*(unsigned long *)(opcode + 2)) >> 8;
         temphand->uv.v = (*(unsigned long *)(opcode + 6)) >> 8;
@@ -706,24 +491,18 @@ uchar *do_uvlist(uchar *opcode) {
 
 // should we be hacking _itrp_gour_flg?
 uchar *do_setcolor(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     gr_set_fcolor(*(unsigned short *)(opcode + 2));
     _itrp_gour_flg = 0;
     return opcode + 4;
 }
 
 uchar *do_getvcolor(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     gr_set_fcolor(_vcolor_tab[*(unsigned short *)(opcode + 2)]);
     _itrp_gour_flg = 0;
     return opcode + 4;
 }
 
 uchar *do_getpcolor(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     gr_set_fcolor(*(unsigned short *)(parm_data + (*(unsigned short *)(opcode + 2))));
     _itrp_gour_flg = 0;
     return opcode + 4;
@@ -732,9 +511,6 @@ uchar *do_getpcolor(uchar *opcode) {
 uchar *do_getvscolor(uchar *opcode) {
     short temp;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     temp = (byte)_vcolor_tab[*(unsigned short *)(opcode + 2)];
     temp |= (*(short *)(opcode + 4)) << 8;
     gr_set_fcolor(gr_get_light_tab()[temp]);
@@ -744,9 +520,6 @@ uchar *do_getvscolor(uchar *opcode) {
 uchar *do_getpscolor(uchar *opcode) {
     short temp;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     temp = (unsigned short)parm_data[*(unsigned short *)(opcode + 2)];
     temp &= 0x00ff;
     temp |= (*(short *)(opcode + 4)) << 8;
@@ -755,70 +528,39 @@ uchar *do_getpscolor(uchar *opcode) {
 }
 
 uchar *do_x_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-
     resbuf[*(short *)(opcode + 2)] = g3_copy_add_delta_x(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6));
     return opcode + 10;
 }
 
 uchar *do_y_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-
     resbuf[*(short *)(opcode + 2)] = g3_copy_add_delta_y(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6));
     return opcode + 10;
 }
 
 uchar *do_z_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-
     resbuf[*(short *)(opcode + 2)] = g3_copy_add_delta_z(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6));
     return opcode + 10;
 }
 
 uchar *do_xy_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-    FlipLong((long *)(opcode + 10));
-
     resbuf[*(short *)(opcode + 2)] =
         g3_copy_add_delta_xy(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6), *(fix *)(opcode + 10));
     return opcode + 14;
 }
 
 uchar *do_xz_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-    FlipLong((long *)(opcode + 10));
-
     resbuf[*(short *)(opcode + 2)] =
         g3_copy_add_delta_xz(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6), *(fix *)(opcode + 10));
     return opcode + 14;
 }
 
 uchar *do_yz_rel(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipLong((long *)(opcode + 6));
-    FlipLong((long *)(opcode + 10));
-
     resbuf[*(short *)(opcode + 2)] =
         g3_copy_add_delta_yz(resbuf[*(short *)(opcode + 4)], *(fix *)(opcode + 6), *(fix *)(opcode + 10));
     return opcode + 14;
 }
 
 uchar *do_icall_p(uchar *opcode) {
-    FlipVector(1, (g3s_vector *)(opcode + 6));
-    FlipShort((short *)(opcode + 18));
-    FlipLong((long *)(opcode + 2));
-
     g3_start_object_angles_x((g3s_vector *)(opcode + 6), *(fixang *)(parm_data + (*(unsigned short *)(opcode + 18))));
     interpreter_loop((uchar *)(*(long *)(opcode + 2)));
     g3_end_object();
@@ -827,10 +569,6 @@ uchar *do_icall_p(uchar *opcode) {
 }
 
 uchar *do_icall_h(uchar *opcode) {
-    FlipVector(1, (g3s_vector *)(opcode + 6));
-    FlipShort((short *)(opcode + 18));
-    FlipLong((long *)(opcode + 2));
-
     g3_start_object_angles_y((g3s_vector *)(opcode + 6), *(fixang *)(parm_data + (*(unsigned short *)(opcode + 18))));
     interpreter_loop((uchar *)(*(long *)(opcode + 2)));
     g3_end_object();
@@ -839,10 +577,6 @@ uchar *do_icall_h(uchar *opcode) {
 }
 
 uchar *do_icall_b(uchar *opcode) {
-    FlipVector(1, (g3s_vector *)(opcode + 6));
-    FlipShort((short *)(opcode + 18));
-    FlipLong((long *)(opcode + 2));
-
     g3_start_object_angles_z((g3s_vector *)(opcode + 6), *(fixang *)(parm_data + (*(unsigned short *)(opcode + 18))));
     interpreter_loop((uchar *)(*(long *)(opcode + 2)));
     g3_end_object();
@@ -851,8 +585,6 @@ uchar *do_icall_b(uchar *opcode) {
 }
 
 uchar *do_sfcal(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-
     interpreter_loop(opcode + (*(unsigned short *)(opcode + 2)));
     return opcode + 4;
 }
@@ -862,10 +594,6 @@ uchar *do_getparms(uchar *opcode) {
     long *src, *dest;
     int count;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipShort((short *)(opcode + 6));
-
     dest = (long *)(parm_data + (*(unsigned short *)(opcode + 2)));
     src = (long *)(parm_ptr + (*(unsigned short *)(opcode + 4)));
     count = *(unsigned short *)(opcode + 6);
@@ -880,10 +608,6 @@ uchar *do_getparms_i(uchar *opcode) {
     long *src, *dest;
     int count;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-    FlipShort((short *)(opcode + 6));
-
     dest = *(long **)(parm_data + (*(unsigned short *)(opcode + 2)));
     src = (long *)(parm_ptr + (*(unsigned short *)(opcode + 4)));
     count = *(unsigned short *)(opcode + 6);
@@ -894,31 +618,7 @@ uchar *do_getparms_i(uchar *opcode) {
 }
 
 uchar *do_dbg(uchar *opcode) {
-// clang-format off
-#ifdef  _itrp_dbg
-  mov     ax, w 4[ebp]    // code
-  and     ax, _itrp_dbg_mask // mask in current debug mode
-  jz      dbg_end         // none currently on
-  cmp     ax, DBG_POLY_ID // itrp_pcode
-  jnz     dbg_nxt1
-  mov     ax, w 6[ebp]    // pgon_id
-  cmp     ax,_pgon_id_low
-  jl      pgon_skip
-  cmp     ax,_pgon_id_high
-  jle     dbg_end
-pgon_skip:
-  movsx	eax,w 2[ebp]    // skip whatever
-  next	eax
-dbg_nxt1:
-  cmp     ax, DBG_POLY_MAX
-  jnz     dbg_end
-  mov     ax, w 6[ebp]
-  mov     _pgon_max, ax
-//        jmp     dbg_end
-#endif
-                                                                      // clang-format on
-                                                                      return opcode +
-                                                                      8;
+    return opcode + 8;
 }
 
 extern void (*g3_tmap_func)();
@@ -928,13 +628,9 @@ uchar *do_tmap_op(uchar *opcode) {
     int count, count2;
     short temp;
 
-    FlipShort((short *)(opcode + 2));
-    FlipShort((short *)(opcode + 4));
-
     count2 = count = *(unsigned short *)(opcode + 4);
     count--;
     do {
-        FlipShort((short *)(opcode + 6 + (count << 1)));
         temp = *(short *)(opcode + 6 + (count << 1));
 
         poly_buf[count] = resbuf[temp];
@@ -953,9 +649,6 @@ uchar *do_tmap_op(uchar *opcode) {
 // if (n*v)<0 then branch to lbl
 // does lit version of jnorm, for flat lighting
 uchar *do_ljnorm(uchar *opcode) {
-    FlipShort((short *)(opcode + 2));
-    FlipVector(2, (g3s_vector *)(opcode + 4));
-
     if (g3_check_normal_facing((g3s_vector *)(opcode + 16), (g3s_vector *)(opcode + 4))) {
         g3_light_obj((g3s_phandle)(opcode + 4), (g3s_phandle)(opcode + 16));
         return opcode + 28;
@@ -967,9 +660,6 @@ uchar *do_ljnorm(uchar *opcode) {
 uchar *do_ldjnorm(uchar *opcode) {
     fix temp;
 
-    FlipShort((short *)(opcode + 2));
-    FlipVector(2, (g3s_vector *)(opcode + 4));
-
     if (g3_check_normal_facing((g3s_vector *)(opcode + 16), (g3s_vector *)(opcode + 4))) {
         temp = g3_vec_dotprod(&_g3d_light_vec, (g3s_vector *)(opcode + 4));
         temp <<= 1;
@@ -986,61 +676,7 @@ uchar *do_ldjnorm(uchar *opcode) {
         return opcode + (*(short *)(opcode + 2)); // surface not visible
 }
 
-// MLA - this routine doesn't appear to ever be called anywhere
-/*
-// check if a surface is facing the viewer and save the view vector and
-// its dot product with everything.  Normalizes view vec and stuff
-// takes esi=point on surface, edi=surface normal (can be unnormalized)
-// trashes eax,ebx,ecx,edx. returns al=true & sign set, if facing
-g3_light_check_normal_facing:
-        call g3_eval_view
-        mov     eax,_g3d_view_vec.x
-        imul    [edi].x
-        mov     ebx,eax
-        mov     ecx,edx
-
-        mov     eax,_g3d_view_vec.y
-        imul    [edi].y
-        add     ebx,eax
-        adc     ecx,edx
-
-        mov     eax,_g3d_view_vec.z
-        imul    [edi].z
-        add     eax,ebx
-        adc     edx,ecx
-
-        // now save this to ldotv
-
-        sets    al      // al=true if facing
-
-        ret
-*/
-
-void FlipShort(short *sh) {
-    /*uchar temp;
-    uchar *src = (uchar *) sh;
-
-    temp = src[0];
-    src[0] = src[1];
-    src[1] = temp;*/
-}
-
-void FlipLong(long *lng) {
-    /*short *src = (short *) lng;
-    short	temp;
-
-    temp = src[0];
-    src[0] = src[1];
-    src[1] = temp;
-
-    FlipShort(src);
-    FlipShort(src+1);*/
-}
-
-void FlipVector(short n, g3s_vector *vec) {
-    /*int		i,j;
-
-    for (i=0; i<n; i++, vec++)
-            for (j=0; j<3; j++)
-                    FlipLong((long *) &vec->xyz[j]);*/
-}
+//external calls to these do-nothing functions can be safely removed
+void FlipShort(short *sh) {}
+void FlipLong(long *lng) {}
+void FlipVector(short n, g3s_vector *vec) {}
