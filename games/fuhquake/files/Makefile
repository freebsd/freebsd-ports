#
# QuakeWorld/FuhQuake Makefile for FreeBSD
#
#	- now should build on non-x86
#	- no longer requires gmake(1)
#	- debug targets support axed out
#	- couple of useful knobs added
#
# Created on Wednesday, May 21 2003 by Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

DO_CFLAGS =	${CFLAGS} -funsigned-char -I${LOCALBASE}/include -I${X11BASE}/include

.if make(svga)
DO_CFLAGS +=	-DNO_WINDOWED_MOUSE
.undef WITHOUT_X86_ASM
.endif

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
DO_CFLAGS +=	-Did386
.endif

.if make(glx)
DO_CFLAGS +=	-DWITH_ZLIB -DWITH_PNG -DWITH_JPEG -DGLQUAKE -DWITH_DGA -DWITH_VMODE
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
DO_CFLAGS +=	-O9 -pipe -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations
.endif

.if defined(WITH_XMMS) && !make(svga)
XMMS_CFLAGS !=	glib-config --cflags
DO_CFLAGS +=	-D__XMMS__ ${XMMS_CFLAGS} ${PTHREAD_CFLAGS}
XMMS_LIBS = -L${X11BASE}/lib -lxmms ${PTHREAD_LIBS}
.endif

########################################################################

CL_COMMON_OBJS = \
		host.o \
		sys_linux.o \
		nonintel.o \
\
		cd_freebsd.o \
		snd_freebsd.o \
		snd_dma.o \
		snd_mem.o \
		snd_mix.o \
\
		cl_input.o \
		keys.o \
\
		net_chan.o \
		net_udp.o \
\
		pr_cmds.o \
		pr_edict.o \
		pr_exec.o \
\
		pmove.o \
		pmovetst.o \
		sv_ccmds.o \
		sv_ents.o \
		sv_init.o \
		sv_main.o \
		sv_move.o \
		sv_nchan.o \
		sv_phys.o \
		sv_save.o \
		sv_send.o \
		sv_user.o \
		sv_world.o \
\
		cl_cam.o \
		cl_cmd.o \
		cl_demo.o \
		cl_ents.o \
		cl_main.o \
		cl_parse.o \
		cl_pred.o \
		cl_screen.o \
		cl_slist.o \
		cl_tent.o \
		cl_view.o \
\
		cmd.o \
		com_msg.o \
		common.o \
		console.o \
		crc.o \
		cvar.o \
		image.o \
		mathlib.o \
		mdfour.o \
		menu.o \
		sbar.o \
		skin.o \
		teamplay.o \
		version.o \
		wad.o \
		zone.o \
\
		auth.o \
		config_manager.o \
		fchecks.o \
		fmod.o \
		fragstats.o \
		ignore.o \
		logging.o \
		match_tools.o \
		modules.o \
		movie.o \
		mp3_player.o \
		rulesets.o \
		utils.o

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
CL_COMMON_AS_OBJS = \
		cl_math.o \
		math.o \
		snd_mixa.o \
		sys_x86.o
.endif

CL_SOFT_OBJS = \
		d_edge.o \
		d_fill.o \
		d_init.o \
		d_modech.o \
		d_polyse.o \
		d_scan.o \
		d_sky.o \
		d_sprite.o \
		d_surf.o \
		d_vars.o \
		d_zpoint.o \
\
		r_aclip.o \
		r_alias.o \
		r_bsp.o \
		r_draw.o \
		r_edge.o \
		r_efrag.o \
		r_light.o \
		r_main.o \
		r_misc.o \
		r_model.o \
		r_part.o \
		r_rast.o \
		r_sky.o \
		r_sprite.o \
		r_surf.o \
		r_vars.o

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
CL_SOFT_AS_OBJS = \
		d_draw.o \
		d_draw16.o \
		d_parta.o \
		d_polysa.o \
		d_scana.o \
		d_spr8.o \
		d_varsa.o \
		r_aclipa.o \
		r_aliasa.o \
		r_drawa.o \
		r_edgea.o \
		r_varsa.o \
		surf8.o
.endif

CL_X11_OBJS = vid_x11.o

CL_GLX_OBJS = \
		gl_draw.o \
		gl_mesh.o \
		gl_model.o \
		gl_ngraph.o \
		gl_refrag.o \
		gl_rlight.o \
		gl_rmain.o \
		gl_rmisc.o \
		gl_rpart.o \
		gl_rsurf.o \
		gl_texture.o \
		gl_warp.o \
		r_part.o \
		vid_common_gl.o \
		vid_glx.o

CL_SVGA_OBJS = vid_svgalib.o

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
CL_SVGA_AS_OBJS = d_copy.o
.endif

CL_COMMON_LIBS = -lm
CL_X11_LIBS = -L${X11BASE}/lib -lX11 -lXext
CL_SVGA_LIBS = -L${LOCALBASE}/lib -lvga
CL_GLX_LIBS = -L${LOCALBASE}/lib -lpng -ljpeg -L${X11BASE}/lib -lGL -lXxf86dga -lXxf86vm

.c.o:
		${CC} ${DO_CFLAGS} -c $< -o $*.o

.s.o:
		${CC} ${DO_CFLAGS} -DELF -x assembler-with-cpp -c $< -o $*.o

x11:	${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} \
	${CL_SOFT_OBJS} ${CL_SOFT_AS_OBJS} ${CL_X11_OBJS}
		${CC} ${CFLAGS} -o fuhquake-x11 \
			${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} ${CL_SOFT_OBJS} \
			${CL_SOFT_AS_OBJS} ${CL_X11_OBJS} \
			${CL_COMMON_LIBS} ${CL_X11_LIBS} ${XMMS_LIBS}

glx:	${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} ${CL_GLX_OBJS}
		${CC} ${CFLAGS} -o fuhquake-glx \
			${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} ${CL_GLX_OBJS} \
			${CL_COMMON_LIBS} ${CL_GLX_LIBS} ${XMMS_LIBS}

svga:	${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} \
	${CL_SOFT_OBJS} ${CL_SOFT_AS_OBJS} ${CL_SVGA_OBJS} ${CL_SVGA_AS_OBJS}
		${CC} ${DO_CFLAGS} -o fuhquake-svga \
			${CL_COMMON_OBJS} ${CL_COMMON_AS_OBJS} ${CL_SOFT_OBJS} \
			${CL_SOFT_AS_OBJS} ${CL_SVGA_OBJS} ${CL_SVGA_AS_OBJS} \
			${CL_COMMON_LIBS} ${CL_SVGA_LIBS} ${XMMS_LIBS}

clean:
		-rm -f *.o *.core
