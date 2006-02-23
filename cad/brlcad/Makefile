# New ports collection makefile for:	brlcad
# Date created:		Jan 2005
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	brlcad
PORTVERSION=	7.6.6
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	brlcad

MAINTAINER=	erik@smluc.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		rle.1:${PORTSDIR}/graphics/urt \
		tcl84:${PORTSDIR}/lang/tcl84

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes

PREFIX?=	${LOCALBASE}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
NO_MTREE=	yes
INSTALLS_SHLIB=	yes	# Not really useful, but pet portlint

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.4
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-libs="-lpng" --program-transform-name="" \
		--disable-tcl-build --disable-jove
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	wish.1 awf.1 comgeom-g.1 g-iges.1 iges-g.1 patch-g.1 rpatch.1 ug-g.1   \
	asc-nmg.1 bot_shell-vtk.1 conv-vg2g.1 cy-g.1 dbclean.1 dxf-g.1 enf-g.1 \
	euclid-g.1 fast4-g.1 g-acad.1 g-dxf.1 g-euclid.1 g-nff.1 g-nmg.1       \
	g-obj.1 g-shell.rect.1 g-stl.1 g-tankill.1 g-vrml.1 g-x3d.1 g2asc.1    \
	nastran-g.1 nmg-bot.1 nmg-rib.1 pix2asc.1 ply-g.1 poly-bot.1 proe-g.1  \
	stl-g.1 tankill-g.1 viewpoint-g.1 fbserv.1 rt.1 rt_bot_faces.1         \
	rtarea.1 rtcheck.1 rtedge.1 rtg3.1 rthide.1 rtpp.1 rtrange.1 rtray.1   \
	rtregis.1 rtscale.1 bw-fb.1 rtshot.1 rtwalk.1 rtweight.1 rtxray.1      \
	anim_cascade.1 anim_fly.1 anim_hardtrack.1 anim_keyread.1              \
	anim_lookat.1 anim_offset.1 anim_orient.1 anim_script.1 anim_sort.1    \
	anim_time.1 anim_track.1 anim_turn.1 chan_mult.1 chan_permute.1        \
	brlman.1 cat-fb.1 cell-fb.1 cmap-fb.1 fb-bw.1 fb-fb.1 fb-cmap.1        \
	fb-orle.1 fb-pix.1 fb-png.1 fb-rle.1 fbanim.1 fbcbars.1 fbclear.1      \
	fbcmap.1 fbcmrot.1 fbcolor.1 fbfade.1 fbframe.1 fbfree.1 fbgamma.1     \
	fbgrid.1 fbhelp.1 fblabel.1 fbline.1 fbpoint.1 fbscanplot.1            \
	fbstretch.1 fbzoom.1 gif-fb.1 gif2fb.1 orle-fb.1 pix-fb.1              \
	pixautosize.1 pl-fb.1 png-fb.1 polar-fb.1 pp-fb.1 rle-fb.1 fbed.1      \
	g_diff.1 g_lint.1 g_qa.1 halftone.1 all_sf.1 showtherm.1 firpass.1     \
	irdisp.1 ir-sgi.1 ir-X.1 secpass.1 shapefact.1 lgt.1 cad_boundp.1      \
	cad_parea.1 mged.1 mk_bolt.1 mk_gastank.1 mk_handle.1 mk_window.1      \
	mk_winfrm.1 mk_wire.1 nirt.1 showshot.1 picket_fence.1 remrt.1         \
	rttherm.1 ssamp-bw.1 scriptsort.1 tabinterp.1 tabsub.1 alias-pix.1     \
	ap-pix.1 asc-pl.1 azel.1 bary.1 brlcad.1 buffer.1 bw-imp.1 bw-pix.1    \
	bw-png.1 bw-ps.1 bw-rle.1 bw3-pix.1 bwcrop.1 bwdiff.1 bwfilter.1       \
	bwhist.1 bwhisteq.1 bwmod.1 bwrect.1 bwrot.1 bwscale.1 bwshrink.1      \
	bwstat.1 bwthresh.1 cv.1 dbcp.1 decimate.1 dpix-pix.1 dunncolor.1      \
	dunnsnap.1 gencolor.1 hd.1 imgdims.1 loop.1 mac-pix.1 morphedit.1      \
	op-bw.1 orle-pix.1 pcd-pix.1 pix-alias.1 pix-bw.1 pix-bw3.1 pix-orle.1 \
	pix-png.1 pix-ps.1 pix-rle.1 pix-sun.1 pixbackgnd.1 pixbgstrip.1       \
	pixblend.1 pixborder.1 pixbustup.1 pixclump.1 pixcolors.1 pixcut.1     \
	pixdiff.1 pixdsplit.1 pixfade.1 pixfilter.1 pixhalve.1 pixhist.1       \
	pixhist3d-pl.1 pixhist3d.1 pixinterp2x.1 pixmatte.1 pixmerge.1         \
	pixmorph.1 pixrect.1 pixrot.1 pixsaturate.1 pixscale.1 pixshrink.1     \
	pixstat.1 pixsubst.1 pixtile.1 pixuntile.1 pl-X.1 pl-X10.1 pl-asc.1    \
	pl-hpgl.1 pl-pl.1 pl-ps.1 pl-sgi.1 pl-starbase.1 pl-tek.1 plcolor.1    \
	pldebug.1 plgetframe.1 plline2.1 plrot.1 png-bw.1 png-pix.1 png_info.1 \
	query.1 rle-pix.1 sun-pix.1 terrain.1 wavelet.1 vas4.1 vdeck.1

MAN3=	3DBorder.3 AddOption.3 BindTable.3 CanvPsY.3 CanvTkwin.3 CanvTxtInfo.3 \
	Clipboard.3 ClrSelect.3 ConfigWidg.3 ConfigWind.3 CoordToWin.3         \
	CrtCmHdlr.3 CrtErrHdlr.3 CrtGenHdlr.3 CrtImgType.3 CrtItemType.3       \
	CrtPhImgFmt.3 CrtSelHdlr.3 CrtWindow.3 DeleteImg.3 DrawFocHlt.3        \
	EventHndlr.3 FindPhoto.3 FontId.3 FreeXId.3 GeomReq.3 GetAnchor.3      \
	GetBitmap.3 GetCapStyl.3 GetClrmap.3 GetColor.3 GetCursor.3 GetDash.3  \
	GetFont.3 GetGC.3 GetHINSTANCE.3 GetHWND.3 GetImage.3 GetJoinStl.3     \
	GetJustify.3 GetOption.3 GetPixels.3 GetPixmap.3 GetRelief.3           \
	GetRootCrd.3 GetScroll.3 Grab.3 GetSelect.3 GetUid.3 GetVRoot.3        \
	GetVisual.3 HWNDToWindow.3 HandleEvent.3 IdToWindow.3 ImgChanged.3     \
	InternAtom.3 MainLoop.3 MainWin.3 MaintGeom.3 ManageGeom.3 MapWindow.3 \
	MeasureChar.3 MoveToplev.3 Name.3 NameOfImg.3 OwnSelect.3 ParseArgv.3  \
	QWinEvent.3 Restack.3 RestrictEv.3 SetCaret.3 SetAppName.3 SetClass.3  \
	SetClassProcs.3 SetGrid.3 SetOptions.3 SetVisual.3 StrictMotif.3       \
	TextLayout.3 TkInitStubs.3 Tk_Init.3 Tk_Main.3 WindowId.3 htond.3      \
	libbu.3 redblack.3 libplot3.3 librt.3 libfb.3 libwdb.3 liborle.3       \
	libcursor.3

MAN5=	bw.5 cmap.5 pix.5 plot3.5

MANN=	bell.n bind.n bindtags.n bitmap.n button.n canvas.n checkbutton.n      \
	chooseColor.n chooseDirectory.n clipboard.n colors.n console.n         \
	cursors.n destroy.n dialog.n entry.n event.n focus.n focusNext.n font.n\
	frame.n getOpenFile.n grab.n grid.n image.n keysyms.n label.n          \
	labelframe.n listbox.n loadTk.n lower.n menu.n menubar.n menubutton.n  \
	message.n messageBox.n option.n optionMenu.n options.n pack-old.n      \
	pack.n palette.n panedwindow.n photo.n place.n popup.n radiobutton.n   \
	raise.n scale.n scrollbar.n selection.n send.n spinbox.n text.n tk.n   \
	tkerror.n tkvars.n tkwait.n toplevel.n winfo.n wm.n body.n class.n     \
	code.n configbody.n delete.n ensemble.n find.n is.n itcl.n itclvars.n  \
	local.n scope.n Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n\
	iwidgets_buttonbox.n iwidgets_calendar.n iwidgets_canvasprintbox.n     \
	iwidgets_canvasprintdialog.n iwidgets_checkbox.n iwidgets_combobox.n   \
	iwidgets_dateentry.n iwidgets_datefield.n iwidgets_dialog.n            \
	iwidgets_dialogshell.n iwidgets_disjointlistbox.n iwidgets_entryfield.n\
	iwidgets_extbutton.n iwidgets_extfileselectionbox.n                    \
	iwidgets_extfileselectiondialog.n iwidgets_feedback.n                  \
	iwidgets_fileselectionbox.n iwidgets_fileselectiondialog.n             \
	iwidgets_finddialog.n iwidgets_hierarchy.n iwidgets_hyperhelp.n        \
	iwidgets_labeledframe.n iwidgets_labeledwidget.n iwidgets_mainwindow.n \
	iwidgets_menubar.n iwidgets_messagebox.n iwidgets_messagedialog.n      \
	iwidgets_notebook.n iwidgets_optionmenu.n iwidgets_panedwindow.n       \
	iwidgets_promptdialog.n iwidgets_pushbutton.n iwidgets_radiobox.n      \
	iwidgets_scopedobject.n iwidgets_scrolledcanvas.n                      \
	iwidgets_scrolledframe.n iwidgets_scrolledhtml.n                       \
	iwidgets_scrolledlistbox.n iwidgets_scrolledtext.n                     \
	iwidgets_selectionbox.n iwidgets_selectiondialog.n iwidgets_shell.n    \
	iwidgets_spindate.n iwidgets_spinint.n iwidgets_spinner.n              \
	iwidgets_spintime.n iwidgets_tabnotebook.n iwidgets_tabset.n           \
	iwidgets_timeentry.n iwidgets_timefield.n iwidgets_toolbar.n           \
	iwidgets_watch.n

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LDFLAGS+=	${PTHREAD_LIBS}
BROKEN=		"Does not compile on FreeBSD-${OSREL}"
.endif

.if !(${ARCH} == i386 || ${ARCH} == amd64)
IGNORE=		dumps core on ${ARCH}
.endif

.ifndef WITHOUT_OPTIMIZATION
CONFIGURE_ARGS+=	--disable-debug
.if !(${ARCH} == alpha || ${ARCH} == sparc64 || ${ARCH} == amd64)
CONFIGURE_ARGS+=	--enable-optimized
.endif
.else
CONFIGURE_ARGS+=	--disable-dependency-tracking --disable-libtool-lock
.endif

.ifndef (WITHOUT_OPTIMIZATION)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} Hit CTRL+C now and build an unoptimized version of brlcad by
	@${ECHO_MSG} specifying -DWITHOUT_OPTIMIZATION at the command line!
	@${ECHO_MSG}
	@sleep 2
.endif

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}+g;'	\
		${WRKSRC}/mged.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${PREFIX}/bin/mged.sh

.include <bsd.port.post.mk>
