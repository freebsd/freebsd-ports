# New ports collection makefile for:	brlcad
# Date created:		Jan 2005
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	brlcad
PORTVERSION=	7.16.8
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/BRL-CAD%20Source/${PORTVERSION}

MAINTAINER=	erik@brlcad.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/jama_lu.h:${PORTSDIR}/math/jama	\
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		rle.1:${PORTSDIR}/graphics/urt

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GL=		gl
USE_XORG=	x11 xt xi xproto xext inputproto
USE_GMAKE=	yes
USE_TK=		85

PREFIX?=	${LOCALBASE}/${PORTNAME}
GNU_CONFIGURE=	yes
NO_MTREE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.5\
 -I${LOCALBASE}/include/tk8.5 -I${LOCALBASE}/include/tnt
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		TKINCDIR=${LOCALBASE}/include/tk8.5
CONFIGURE_ARGS+=--with-libs="-lpng ${EXTRA_LIBS}" --program-transform-name=""	\
	--x-includes=${LOCALBASE}/include --x-libraries=${LOCALBASE}/libs	\
	--disable-jove-build --disable-strict-build				\
	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR}				\
	--with-tkinclude=${TK_INCDIR}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	dataprobe.1 fedex.1 fedex_plus.1 mkProbe.1 awf.1 g-iges.1 iges-g.1	\
	bot_dump.1 g2asc.1 pix2asc.1 bot_shell-vtk.1 comgeom-g.1		\
	conv-vg2g.1 cy-g.1 dbclean.1 dbupgrade.1 dxf-g.1 g-dxf.1 enf-g.1	\
	euclid-g.1 g-euclid.1 fast4-g.1 g-egg.1 g-acad.1 g-nff.1 g-obj.1	\
	g-shell.rect.1 g-var.1 g-vrml.1 g-x3d.1 nastran-g.1 asc-nmg.1		\
	g-nmg.1 nmg-bot.1 nmg-rib.1 patch-g.1 rpatch.1 ply-g.1 poly-bot.1	\
	proe-g.1 g-stl.1 stl-g.1 g-tankill.1 tankill-g.1 viewpoint-g.1		\
	fbserv.1 reshoot.1 rt_bot_faces.1 rtg3.1 rthide.1 rtpp.1 rtrange.1	\
	rtray.1 rtregis.1 rtscale.1 rtshot.1 rtwalk.1 rtweight.1 rtxray.1	\
	anim_script.1 anim_sort.1 anim_time.1 anim_track.1 anim_turn.1		\
	chan_mult.1 chan_permute.1 brlman.1 canonize.1 bw-fb.1 cat-fb.1		\
	cell-fb.1 cmap-fb.1 fb-bw.1 fb-cmap.1 fb-fb.1 fb-orle.1 fb-pix.1	\
	pl-fb.1 fb-png.1 fb-rle.1 fbanim.1 fbcbars.1 fbclear.1 fbcmap.1		\
	fbcmrot.1 fbcolor.1 fbfade.1 fbframe.1 fbfree.1 fbgamma.1 fbgrid.1	\
	fbhelp.1 fblabel.1 fbline.1 fbpoint.1 fbscanplot.1 fbstretch.1		\
	fbzoom.1 gif-fb.1 gif2fb.1 orle-fb.1 pix-fb.1 pixautosize.1		\
	png-fb.1 polar-fb.1 pp-fb.1 rle-fb.1 fbed.1 g_diff.1 g_lint.1		\
	halftone.1 showtherm.1 firpass.1 irdisp.1 ir-sgi.1 ir-X.1		\
	secpass.1 shapefact.1 lgt.1 cad_boundp.1 cad_parea.1 showshot.1		\
	remrt.1 rttherm.1 ssamp-bw.1 scriptsort.1 tabinterp.1 tabsub.1		\
	ap-pix.1 asc-pl.1 azel.1 bary.1 brlcad.1 buffer.1 bw-imp.1		\
	bw-pix.1 bw-png.1 bw-ps.1 bw-rle.1 bw3-pix.1 bwcrop.1 bwdiff.1		\
	bwfilter.1 bwhist.1 bwhisteq.1 bwmod.1 bwrect.1 bwrot.1 bwshrink.1	\
	bwstat.1 bwthresh.1 cv.1 dbcp.1 decimate.1 dpix-pix.1 dunncolor.1	\
	dunnsnap.1 gencolor.1 hex.1 imgdims.1 loop.1 mac-pix.1 morphedit.1	\
	orle-pix.1 pix-alias.1 pix-bw.1 pix-bw3.1 pix-ppm.1 pix-orle.1		\
	pix-png.1 pix-ps.1 pix-rle.1 pix-sun.1 pixbackgnd.1 pixbgstrip.1	\
	pixblend.1 pixborder.1 pixbustup.1 pixclump.1 pixcolors.1 pixcut.1	\
	pixdiff.1 pixdsplit.1 pixfade.1 pixfilter.1 pixhalve.1 pixhist.1	\
	pixhist3d-pl.1 pixhist3d.1 pixinterp2x.1 pixmatte.1 pixmerge.1		\
	pixmorph.1 pixrect.1 pixrot.1 pixsaturate.1 pixscale.1 pixshrink.1	\
	pixstat.1 pixsubst.1 pixtile.1 pixuntile.1 pl-X.1 pl-asc.1		\
	pl-hpgl.1 pl-pl.1 pl-ps.1 pl-sgi.1 pl-tek.1 plcolor.1 pldebug.1		\
	plgetframe.1 plline2.1 plrot.1 png-bw.1 png-pix.1 png_info.1		\
	query.1 remapid.1 rle-pix.1 sun-pix.1 terrain.1 coil.1 db.1 gqa.1	\
	wavelet.1 vdeck.1 benchmark.1 pixcmp.1 bwscale.1 mged.1 nirt.1		\
	rt.1 rtarea.1 rtcheck.1 rtedge.1 tire.1 enigma.1 brlcad-config.1

MAN3=	RegisterC.3 Stack.3 htond.3 libbu.3 redblack.3 libplot3.3 librt.3	\
	libfb.3 libwdb.3 liborle.3 libcursor.3

MAN5=	bw.5 cmap.5 pix.5 plot3.5

MANN=	code.n configbody.n delete.n ensemble.n find.n is.n itcl.n		\
	itclvars.n local.n scope.n Archetype.n Toplevel.n Widget.n itk.n	\
	itkvars.n usual.n iwidgets_buttonbox.n iwidgets_calendar.n		\
	iwidgets_canvasprintbox.n iwidgets_canvasprintdialog.n			\
	iwidgets_checkbox.n iwidgets_combobox.n iwidgets_dateentry.n		\
	iwidgets_datefield.n iwidgets_dialog.n iwidgets_dialogshell.n		\
	iwidgets_disjointlistbox.n iwidgets_entryfield.n			\
	iwidgets_extbutton.n iwidgets_extfileselectionbox.n			\
	iwidgets_extfileselectiondialog.n iwidgets_feedback.n			\
	iwidgets_fileselectionbox.n iwidgets_fileselectiondialog.n		\
	iwidgets_finddialog.n iwidgets_hierarchy.n iwidgets_hyperhelp.n		\
	iwidgets_labeledframe.n iwidgets_labeledwidget.n			\
	iwidgets_mainwindow.n iwidgets_menubar.n iwidgets_messagebox.n		\
	iwidgets_messagedialog.n iwidgets_notebook.n iwidgets_optionmenu.n	\
	iwidgets_panedwindow.n iwidgets_promptdialog.n				\
	iwidgets_pushbutton.n iwidgets_radiobox.n iwidgets_scopedobject.n	\
	iwidgets_scrolledcanvas.n iwidgets_scrolledframe.n			\
	iwidgets_shell.n iwidgets_scrolledhtml.n				\
	iwidgets_scrolledlistbox.n iwidgets_scrolledtext.n			\
	iwidgets_selectionbox.n iwidgets_selectiondialog.n			\
	iwidgets_spindate.n iwidgets_spinint.n iwidgets_spinner.n		\
	iwidgets_spintime.n iwidgets_tabnotebook.n iwidgets_tabset.n		\
	iwidgets_timeentry.n iwidgets_timefield.n iwidgets_toolbar.n		\
	iwidgets_watch.n tkhtml.n 3ptarb.nged B.nged E.nged M.nged Z.nged	\
	adc.nged ae.nged alias-pix.nged all_sf.nged analyze.nged		\
	anim_cascade.nged anim_fly.nged anim_hardtrack.nged			\
	anim_keyread.nged anim_lookat.nged anim_offset.nged			\
	anim_orient.nged animmate.nged apropos.nged aproposdevel.nged		\
	aproposlib.nged arb.nged bot_condense.nged arced.nged area.nged		\
	arot.nged attach.nged attr.nged autoview.nged bb.nged bev.nged		\
	bo.nged bolt.nged bot_decimate.nged bot_face_fuse.nged			\
	bot_face_sort.nged bot_vertex_fuse.nged build_region.nged c.nged	\
	cat.nged center.nged color.nged comb_color.nged copyeval.nged		\
	copymat.nged cp.nged cpi.nged d.nged dall.nged db.nged			\
	db_glob.nged dbconcat.nged debugbu.nged debugdir.nged			\
	debuglib.nged debugmem.nged debugnmg.nged decompose.nged		\
	delay.nged dm.nged draw.nged dup.nged e_command.nged e_muves.nged	\
	eac.nged echo.nged edcodes.nged edcolor.nged edgedir.nged		\
	edcomb.nged edmater.nged em.nged eqn.nged erase.nged			\
	erase_all.nged ev.nged exit.nged expand.nged export_body.nged		\
	extrude.nged eye_pt.nged facedef.nged facetize.nged find.nged		\
	fracture.nged g.nged garbage_collect.nged gastank.nged gqa.nged		\
	gui.nged handle.nged permute.nged help.nged helpdevel.nged		\
	helplib.nged hide.nged history.nged i.nged idents.nged ill.nged		\
	in.nged inside.nged item.nged journal.nged keep.nged keypoint.nged	\
	kill.nged killall.nged killtree.nged knob.nged l.nged l_muves.nged	\
	labelvert.nged listeval.nged lm.nged loadtk.nged lookat.nged		\
	ls.nged make.nged make_bb.nged mater.nged matpick.nged			\
	memprint.nged mirface.nged mrot.nged mv.nged mvall.nged nirt.nged	\
	nmg_collapse.nged nmg_simplify.nged oed.nged opendb.nged		\
	orientation.nged orot.nged oscale.nged overlay.nged p.nged		\
	pathlist.nged paths.nged ps.nged picket_fence.nged plot.nged		\
	prcolor.nged prefix.nged press.nged preview.nged prj_add.nged		\
	push.nged put_comb.nged putmat.nged q.nged qorot.nged qray.nged		\
	query_ray.nged quit.nged qvrot.nged r.nged rcc-blend.nged		\
	rcc-cap.nged rcc-tgc.nged rcc-tor.nged rcodes.nged			\
	redraw_vlist.nged read_muves.nged red.nged refresh.nged			\
	regdebug.nged regdef.nged regions.nged release.nged rfarb.nged		\
	rm.nged rmater.nged rmats.nged rot.nged rotobj.nged rpp-arch.nged	\
	rpp-cap.nged rrt.nged rt.nged rtcheck.nged rtwizard.nged		\
	savekey.nged saveview.nged sca.nged setview.nged search.nged		\
	sed.nged shader.nged shell.nged showmats.nged size.nged			\
	solids.nged sph-part.nged status.nged summary.nged sv.nged		\
	sync.nged t.nged t_muves.nged ted.nged title.nged tol.nged		\
	tops.nged tor-rcc.nged tra.nged track.nged translate.nged		\
	tree.nged viewsize.nged units.nged vars.nged vdraw.nged view.nged	\
	vnirt.nged vquery_ray.nged vrmgr.nged vrot.nged wcodes.nged		\
	whatid.nged which_shader.nged whichair.nged whichid.nged who.nged	\
	window.nged window_frame.nged wire.nged wmater.nged x.nged		\
	xpush.nged zoom.nged body.n class.n

OPTIONS=	OPTIMIZATION "Build with optimizations" on

.include <bsd.port.pre.mk>

EXTRA_LIBS=	${PTHREAD_LIBS}

.ifdef WITH_OPTIMIZATION
CONFIGURE_ARGS+=	--disable-debug --enable-optimized
.endif

post-patch:
	${REINPLACE_CMD} "s+-exact Tcl 8\.5\.1+Tcl 8.5+" ${WRKSRC}/src/other/tcl/library/init.tcl

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}+g;' ${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${PREFIX}/bin/mged.sh
	${LN} -s ${PREFIX}/bin/mged.sh ${LOCALBASE}/bin/mged.sh

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test)

.include <bsd.port.post.mk>
