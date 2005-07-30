# New ports collection makefile for:	iv
# Date created:		23.Feb.1996
# Whom:			sanpei@yy.cs.keio.ac.jp
#
# $FreeBSD$
#

PORTNAME=	iv
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	japanese graphics
MASTER_SITES=	ftp://interviews.stanford.edu/pub/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	${PORTVERSION}.tar.Z \
		${PORTNAME}${PORTVERSION:S/./_/g}j_gamma.tar.gz

PATCH_SITES=	${MASTER_SITE_PORTS_JP}
PATCHFILES=	${DISTNAME}j-gamma-fixcmpfont.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A toolkit from Stanford University and Silicon Graphics + Japanese patches

FORBIDDEN=	http://vuxml.FreeBSD.org/pkg-ja-iv.html
EXPIRATION_DATE=2005-08-30

# Warning: we cannot use USE_IMAKE.
BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502112
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

USE_GCC=	2.95
USE_XLIB=	yes
DIST_SUBDIR=	iv
WRKSRC=		${WRKDIR}/iv
MAKE_ENV=	CPU=`make CPU`

MANPREFIX=	${PREFIX}/interviews
MANN=		Adjuster.n Banner.n BasicDialog.n Border.n Box2_6.n \
		BrushCmd.n Button2_6.n CGlue.n CSolver.n Catalog.n \
		Clipboard.n ColorCmd.n Command.n CompletionEditor.n \
		Component.n ComponentView.n ConnectTool.n Connector.n \
		Control.n ControlInfo.n Creator.n Damage.n Data.n \
		Deck2_6.n Dialog.n Dispatcher.n Editor.n EditorInfo.n \
		EllipseComp.n ExternView.n FileBrowser.n FileChooser.n \
		FontCmd.n Frame.n GVUpdater.n Glue2_6.n Graphic.n \
		GraphicBlock.n GraphicComp.n GraphicCompTool.n \
		GraphicView.n Grid.n IOCallback.n IOHandler.n \
		ImportCmd.n Interactor.n Iterator.n KeyMap.n \
		LineComp.n LinkComp.n MacroCmd.n MagnifyTool.n \
		Manipulator.n MatchEditor.n Menu2_6.n Message.n \
		MoveTool.n NOPCmd.n PadComp.n Page.n Painter.n \
		Panner.n Path.n Pattern.n PatternCmd.n Perspective.n \
		Picture.n PinComp.n PolygonComp.n PostScriptView.n \
		RasterComp.n RasterRect.n RectComp.n Regexp.n ReqErr.n \
		ReshapeTool.n Resource.n RotateTool.n RpcHdr.n \
		RpcPeer.n RpcReader.n RpcRegistry.n RpcService.n \
		RpcWriter.n Rubband.n ScaleTool.n Scene.n Scroller.n \
		SelectTool.n Selection.n Sensor.n Shape.n SlotComp.n \
		SplineComp.n StateVar.n StateVarView.n StencilComp.n \
		StrBrowser.n StrChooser.n StretchTool.n StringEditor.n \
		Subject.n TextBuffer.n TextComp.n TextDisplay.n \
		TextEditor.n Tool.n TransferFunct.n Tray.n UArray.n \
		UControl.n UHashTable.n ULabel.n UList.n UMap.n \
		UStencil.n Unidraw.n UnidrawIntro.n Vertices.n \
		VerticesComp.n Viewer.n Viewport.n World.n alert.n \
		align.n catcmds.n classes.n datas.n dclock.n doc.n \
		edit.n ellipses.n geomobjs.n globals.n ibuild.n \
		iclass.n idraw.n ifb.n ifc.n iostreamb.n ivmkmf.n \
		kybd.n lines.n logo.n mailbox.n manips.n polygons.n \
		pspaint.n remind.n rpcbuf.n rpcstream.n splines.n \
		statevars.n stateviews.n struct.n transfns.n \
		transforms.n uctrls.n viewcmds.n

INSTALLS_SHLIB=	yes
.if ${PORTOBJFORMAT} == "elf"
IV_LIB_VER=	3
.else
IV_LIB_VER=	3.1
.endif

pre-patch:
	${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/diff-2.0gamma

post-patch:
	@(cd ${WRKSRC}/src/config/InterViews; ${MV} -f iv-freebsd.cf \
	iv-freebsd.cf~; ${SED} -e 's/%%CXX%%/${CXX}/' iv-freebsd.cf~ \
	> iv-freebsd.cf)
.if ${OSVERSION} >= 400002
	@(cd ${WRKSRC}/src/config/InterViews; ${MV} -f iv-freebsd.cf \
	iv-freebsd.cf~; ${SED} -e 's/\-lg\+\+//' iv-freebsd.cf~ \
	> iv-freebsd.cf)
.endif

post-install:
	@${INSTALL_DATA} ${WRKDIR}/idraw-3_1j.ad ${PREFIX}/interviews/lib/all/app-defaults/idraw
# need these in ${PREFIX}/lib so that ldconfig can find them
	@${LN} -fs ../interviews/lib/libIV.so.${IV_LIB_VER} ${PREFIX}/lib
	@${LN} -fs ../interviews/lib/libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib
	@${LN} -fs ${PREFIX}/lib/libIV.so.${IV_LIB_VER} ${PREFIX}/lib/libIV.so
	@${LN} -fs ${PREFIX}/lib/libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib/libUnidraw.so

.include <bsd.port.post.mk>
