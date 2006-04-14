# New ports collection makefile for:	brlcad
# Date created:		Jan 2005
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	brlcad
PORTVERSION=	7.8.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	brlcad

MAINTAINER=	erik@smluc.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		rle.1:${PORTSDIR}/graphics/urt

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes

PREFIX?=	${LOCALBASE}/${PORTNAME}
GNU_CONFIGURE=	yes
NO_MTREE=	yes
INSTALLS_SHLIB=	yes	# Not really useful, but pet portlint

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.4
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-libs="-lpng" --program-transform-name="" \
		--disable-jove-build
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	alias-pix.1 all_sf.1 anim_cascade.1 anim_fly.1 anim_hardtrack.1		\
	anim_keyread.1 anim_lookat.1 anim_offset.1 anim_orient.1		\
	anim_script.1 anim_sort.1 anim_time.1 anim_track.1 anim_turn.1		\
	ap-pix.1 asc-nmg.1 asc-pl.1 awf.1 azel.1 bary.1 benchmark.1		\
	bot_shell-vtk.1 brlcad.1 brlman.1 buffer.1 bw-fb.1 bw-imp.1 bw-pix.1	\
	bw-png.1 bw-ps.1 bw-rle.1 bw3-pix.1 bwcrop.1 bwdiff.1 bwfilter.1	\
	bwhist.1 bwhisteq.1 bwmod.1 bwrect.1 bwrot.1 bwscale.1 bwshrink.1	\
	bwstat.1 bwthresh.1 cad_boundp.1 cad_parea.1 cat-fb.1 cell-fb.1		\
	chan_mult.1 chan_permute.1 cmap-fb.1 comgeom-g.1 conv-vg2g.1 cv.1	\
	cy-g.1 dbclean.1 dbcp.1 decimate.1 dpix-pix.1 dunncolor.1 dunnsnap.1	\
	dxf-g.1 enf-g.1 euclid-g.1 fast4-g.1 fb-bw.1 fb-cmap.1 fb-fb.1		\
	fb-orle.1 fb-pix.1 fb-png.1 fb-rle.1 fbanim.1 fbcbars.1 fbclear.1	\
	fbcmap.1 fbcmrot.1 fbcolor.1 fbed.1 fbfade.1 fbframe.1 fbfree.1		\
	fbgamma.1 fbgrid.1 fbhelp.1 fblabel.1 fbline.1 fbpoint.1 fbscanplot.1	\
	fbserv.1 fbstretch.1 fbzoom.1 firpass.1 g-acad.1 g-dxf.1 g-euclid.1	\
	g-iges.1 g-nff.1 g-nmg.1 g-obj.1 g-shell.rect.1 g-stl.1 g-tankill.1	\
	g-vrml.1 g-x3d.1 g2asc.1 g_diff.1 g_lint.1 g_qa.1 gencolor.1 gif-fb.1	\
	gif2fb.1 halftone.1 hd.1 iges-g.1 imgdims.1 ir-X.1 ir-sgi.1 irdisp.1	\
	lgt.1 loop.1 mac-pix.1 mged.1 mk_bolt.1 mk_gastank.1 mk_handle.1	\
	mk_window.1 mk_winfrm.1 mk_wire.1 morphedit.1 nastran-g.1 nirt.1	\
	nmg-bot.1 nmg-rib.1 op-bw.1 orle-fb.1 orle-pix.1 patch-g.1 pcd-pix.1	\
	picket_fence.1 pix-alias.1 pix-bw.1 pix-bw3.1 pix-fb.1 pix-orle.1	\
	pix-png.1 pix-ps.1 pix-rle.1 pix-sun.1 pix2asc.1 pixautosize.1		\
	pixbackgnd.1 pixbgstrip.1 pixblend.1 pixborder.1 pixbustup.1		\
	pixclump.1 pixcolors.1 pixcut.1 pixdiff.1 pixdsplit.1 pixfade.1		\
	pixfilter.1 pixhalve.1 pixhist.1 pixhist3d-pl.1 pixhist3d.1		\
	pixinterp2x.1 pixmatte.1 pixmerge.1 pixmorph.1 pixrect.1 pixrot.1	\
	pixsaturate.1 pixscale.1 pixshrink.1 pixstat.1 pixsubst.1 pixtile.1	\
	pixuntile.1 pl-X.1 pl-X10.1 pl-asc.1 pl-fb.1 pl-hpgl.1 pl-pl.1		\
	pl-ps.1 pl-sgi.1 pl-starbase.1 pl-tek.1 plcolor.1 pldebug.1		\
	plgetframe.1 plline2.1 plrot.1 ply-g.1 png-bw.1 png-fb.1 png-pix.1	\
	png_info.1 polar-fb.1 poly-bot.1 pp-fb.1 proe-g.1 query.1 remrt.1	\
	rle-fb.1 rle-pix.1 rpatch.1 rt.1 rt_bot_faces.1 rtarea.1 rtcheck.1	\
	rtedge.1 rtg3.1 rthide.1 rtpp.1 rtrange.1 rtray.1 rtregis.1 rtscale.1	\
	rtshot.1 rttherm.1 rtwalk.1 rtweight.1 rtxray.1 scriptsort.1		\
	secpass.1 shapefact.1 showshot.1 showtherm.1 ssamp-bw.1 stl-g.1		\
	sun-pix.1 tabinterp.1 tabsub.1 tankill-g.1 tclsh.1 terrain.1 ug-g.1	\
	vas4.1 vdeck.1 viewpoint-g.1 wavelet.1 wish.1

MAN3=	3DBorder.3 Access.3 AddErrInfo.3 AddOption.3 Alloc.3 AllowExc.3		\
	AppInit.3 AssocData.3 Async.3 BackgdErr.3 Backslash.3 BindTable.3	\
	BoolObj.3 ByteArrObj.3 CallDel.3 CanvPsY.3 CanvTkwin.3 CanvTxtInfo.3	\
	ChnlStack.3 Clipboard.3 ClrSelect.3 CmdCmplt.3 Concat.3 ConfigWidg.3	\
	ConfigWind.3 CoordToWin.3 CrtChannel.3 CrtChnlHdlr.3 CrtCloseHdlr.3	\
	CrtCmHdlr.3 CrtCommand.3 CrtErrHdlr.3 CrtFileHdlr.3 CrtGenHdlr.3	\
	CrtImgType.3 CrtInterp.3 CrtItemType.3 CrtMathFnc.3 CrtObjCmd.3		\
	CrtPhImgFmt.3 CrtSelHdlr.3 CrtSlave.3 CrtTimerHdlr.3 CrtTrace.3		\
	CrtWindow.3 DString.3 DeleteImg.3 DetachPids.3 DoOneEvent.3		\
	DoWhenIdle.3 DoubleObj.3 DrawFocHlt.3 DumpActiveMemory.3 Encoding.3	\
	Environment.3 Eval.3 EventHndlr.3 Exit.3 ExprLong.3 ExprLongObj.3	\
	FileSystem.3 FindExec.3 FindPhoto.3 FontId.3 FreeXId.3 GeomReq.3	\
	GetAnchor.3 GetBitmap.3 GetCapStyl.3 GetClrmap.3 GetColor.3		\
	GetCursor.3 GetCwd.3 GetDash.3 GetFont.3 GetGC.3 GetHINSTANCE.3		\
	GetHWND.3 GetHostName.3 GetImage.3 GetIndex.3 GetInt.3 GetJoinStl.3	\
	GetJustify.3 GetOpnFl.3 GetOption.3 GetPixels.3 GetPixmap.3		\
	GetRelief.3 GetRootCrd.3 GetScroll.3 GetSelect.3 GetStdChan.3		\
	GetTime.3 GetUid.3 GetVRoot.3 GetVersion.3 GetVisual.3 Grab.3		\
	HWNDToWindow.3 HandleEvent.3 Hash.3 IdToWindow.3 ImgChanged.3 Init.3	\
	InitStubs.3 IntObj.3 InternAtom.3 Interp.3 LinkVar.3 ListObj.3		\
	Macintosh.3 MainLoop.3 MainWin.3 MaintGeom.3 ManageGeom.3 MapWindow.3	\
	MeasureChar.3 MoveToplev.3 Name.3 NameOfImg.3 Notifier.3 Object.3	\
	ObjectType.3 OpenFileChnl.3 OpenTcp.3 OwnSelect.3 Panic.3 ParseArgv.3	\
	ParseCmd.3 PkgRequire.3 Preserve.3 PrintDbl.3 QWinEvent.3		\
	RecEvalObj.3 RecordEval.3 RegExp.3 Restack.3 RestrictEv.3		\
	SaveResult.3 SetAppName.3 SetCaret.3 SetClass.3 SetClassProcs.3		\
	SetErrno.3 SetGrid.3 SetOptions.3 SetRecLmt.3 SetResult.3 SetVar.3	\
	SetVisual.3 Signal.3 Sleep.3 SourceRCFile.3 SplitList.3 SplitPath.3	\
	StaticPkg.3 StdChannels.3 StrMatch.3 StrictMotif.3 StringObj.3		\
	SubstObj.3 TCL_MEM_DEBUG.3 Tcl_Main.3 TextLayout.3 Thread.3		\
	TkInitStubs.3 Tk_Init.3 Tk_Main.3 ToUpper.3 TraceCmd.3 TraceVar.3	\
	Translate.3 UniCharIsAlpha.3 UpVar.3 Utf.3 WindowId.3 WrongNumArgs.3	\
	htond.3 libbu.3 libcursor.3 libfb.3 liborle.3 libplot3.3 librt.3	\
	libwdb.3 redblack.3

MAN5=	bw.5 cmap.5 pix.5 plot3.5

MANN=	Archetype.n Tcl.n Toplevel.n Widget.n after.n append.n array.n		\
	bell.n bgerror.n binary.n bind.n bindtags.n bitmap.n body.n break.n	\
	button.n canvas.n case.n catch.n cd.n checkbutton.n chooseColor.n	\
	chooseDirectory.n class.n clipboard.n clock.n close.n code.n colors.n	\
	concat.n configbody.n console.n continue.n cursors.n dde.n delete.n	\
	destroy.n dialog.n encoding.n ensemble.n entry.n eof.n error.n eval.n	\
	event.n exec.n exit.n expr.n fblocked.n fconfigure.n fcopy.n file.n	\
	fileevent.n filename.n find.n flush.n focus.n focusNext.n font.n	\
	for.n foreach.n format.n frame.n getOpenFile.n gets.n glob.n global.n	\
	grab.n grid.n history.n http.n if.n image.n incr.n info.n interp.n	\
	is.n itcl.n itclvars.n itk.n itkvars.n iwidgets_buttonbox.n		\
	iwidgets_calendar.n iwidgets_canvasprintbox.n				\
	iwidgets_canvasprintdialog.n iwidgets_checkbox.n iwidgets_combobox.n	\
	iwidgets_dateentry.n iwidgets_datefield.n iwidgets_dialog.n		\
	iwidgets_dialogshell.n iwidgets_disjointlistbox.n			\
	iwidgets_entryfield.n iwidgets_extbutton.n				\
	iwidgets_extfileselectionbox.n iwidgets_extfileselectiondialog.n	\
	iwidgets_feedback.n iwidgets_fileselectionbox.n				\
	iwidgets_fileselectiondialog.n iwidgets_finddialog.n			\
	iwidgets_hierarchy.n iwidgets_hyperhelp.n iwidgets_labeledframe.n	\
	iwidgets_labeledwidget.n iwidgets_mainwindow.n iwidgets_menubar.n	\
	iwidgets_messagebox.n iwidgets_messagedialog.n iwidgets_notebook.n	\
	iwidgets_optionmenu.n iwidgets_panedwindow.n iwidgets_promptdialog.n	\
	iwidgets_pushbutton.n iwidgets_radiobox.n iwidgets_scopedobject.n	\
	iwidgets_scrolledcanvas.n iwidgets_scrolledframe.n			\
	iwidgets_scrolledhtml.n iwidgets_scrolledlistbox.n			\
	iwidgets_scrolledtext.n iwidgets_selectionbox.n				\
	iwidgets_selectiondialog.n iwidgets_shell.n iwidgets_spindate.n		\
	iwidgets_spinint.n iwidgets_spinner.n iwidgets_spintime.n		\
	iwidgets_tabnotebook.n iwidgets_tabset.n iwidgets_timeentry.n		\
	iwidgets_timefield.n iwidgets_toolbar.n iwidgets_watch.n join.n		\
	keysyms.n label.n labelframe.n lappend.n library.n lindex.n linsert.n	\
	list.n listbox.n llength.n load.n loadTk.n local.n lower.n lrange.n	\
	lreplace.n lsearch.n lset.n lsort.n memory.n menu.n menubar.n		\
	menubutton.n message.n messageBox.n msgcat.n namespace.n open.n		\
	option.n optionMenu.n options.n pack-old.n pack.n package.n		\
	packagens.n palette.n panedwindow.n photo.n pid.n pkgMkIndex.n		\
	place.n popup.n proc.n puts.n pwd.n radiobutton.n raise.n re_syntax.n	\
	read.n regexp.n registry.n regsub.n rename.n resource.n return.n	\
	safe.n scale.n scan.n scope.n scrollbar.n seek.n selection.n send.n	\
	set.n socket.n source.n spinbox.n split.n string.n subst.n switch.n	\
	tcltest.n tclvars.n tell.n text.n time.n tk.n tkerror.n tkvars.n	\
	tkwait.n toplevel.n trace.n unknown.n unset.n update.n uplevel.n	\
	upvar.n usual.n variable.n vwait.n while.n winfo.n wm.n

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LDFLAGS+=	${PTHREAD_LIBS}
BROKEN=		Does not compile on FreeBSD-${OSREL}
.endif

.if !(${ARCH} == i386 || ${ARCH} == amd64)
IGNORE=		dumps core on ${ARCH}
.endif

.ifndef WITHOUT_OPTIMIZATION
CONFIGURE_ARGS+=	--disable-debug
#.if !(${ARCH} == alpha || ${ARCH} == sparc64 || ${ARCH} == amd64)
.if !(${ARCH} == alpha || ${ARCH} == sparc64)
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
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${LOCALBASE}/bin/mged.sh

.include <bsd.port.post.mk>
