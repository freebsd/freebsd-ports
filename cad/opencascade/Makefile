# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	OpenCASCADE
PORTVERSION=	6.6.0
PORTREVISION=	1
CATEGORIES=	cad science
MASTER_SITES=	http://files.opencascade.com/OCCT/OCC_${PORTVERSION}_release/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

LICENSE=	OCTPL
LICENSE_NAME=	Open CASCADE Technology Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		bison shebangfix
USE_XORG=	xmu
SHEBANG_FILES=	adm/cmake/draw.sh env_amk.sh draw.sh xcode.sh env.sh draw_amk.sh	\
		codeblocks.sh custom.sh custom_amk.sh.in

OPTIONS_DEFINE=	TBB VIS OCAF DE DRAW FI QT JAVA DATA DOCS EXAMPLES
TBB_DESC=	"Build with TBB"
VIS_DESC=	"Build Visualizazion module (requires OpenGL, freetype, ftgl and gl2ps)"
OCAF_DESC=	"Build Application Framework (requires VIS)"
DE_DESC=	"Build DataExchange module (requires OCAF)"
DRAW_DESC=	"Build Test Harness (requires DE and TCL)"
FI_DESC=	"Enable freeimage support"
QT_DESC=	"Enable QT support"
JAVA_DESC=	"Enable Java support"
OPTIONS_DEFAULT=TBB VIS OCAF DE DRAW FI DATA DOCS EXAMPLES

WRKSRC=		${WRKDIR}/ros
REINPLACE_ARGS=	-i ""
USE_AUTOTOOLS=	aclocal libtoolize autoheader automake
LIBTOOLIZE_ARGS=--force --copy --automake
AUTOMAKE_ARGS=	--add-missing --copy --gnu
ACLOCAL_ARGS=
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	LOCCROOT=${LOCCROOT}
USE_LDCONFIG=	yes

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTBB}
LIB_DEPENDS+=	libtbb.so:${PORTSDIR}/devel/tbb
CONFIGURE_ARGS+=--with-tbb-include=${LOCALBASE}/include	\
		--with-tbb-library=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MVIS}
CONFIGURE_ARGS+=--enable-vis			\
		--with-ftgl=${LOCALBASE}	\
		--with-freetype=${LOCALBASE}	\
		--with-gl2ps=${LOCALBASE}
USE_GL=		glu
LIB_DEPENDS+=	libftgl.so:${PORTSDIR}/graphics/ftgl		\
		libfreetype.so:${PORTSDIR}/print/freetype2	\
		libgl2ps.so:${PORTSDIR}/print/gl2ps
PLIST_SUB+=	VIS=""
. if ${PORT_OPTIONS:MOCAF}
CONFIGURE_ARGS+=--enable-caf
PLIST_SUB+=	OCAF=""
.  if ${PORT_OPTIONS:MDE}
CONFIGURE_ARGS+=--enable-dxe
PLIST_SUB+=	DE=""
.   if ${PORT_OPTIONS:MDRAW}
CONFIGURE_ARGS+=--enable-draw			\
		--with-tcl=${TCL_LIBDIR}	\
		--with-tk=${TK_LIBDIR}
USE_TK=		84+
LIB_DEPENDS+=	libitcl.so.${ITCL_VER}:${PORTSDIR}/lang/itcl		\
		libTix${TIX_VER}.so:${PORTSDIR}/x11-toolkits/tix
ITCL_VER=	3
TIX_VER=	8.4.3
TIX_MM=		8.4.3
PLIST_SUB+=	DRAW=""
.   else
CONFIGURE_ARGS+=--without-tcl --disable-draw
PLIST_SUB+=	DRAW="@comment "
.   endif
.  else
CONFIGURE_ARGS+=--disable-dxe --without-tcl --disable-draw
PLIST_SUB+=	DRAW="@comment " DE="@comment "
.  endif
. else
CONFIGURE_ARGS+=--disable-caf --without-tcl --disable-draw --disable-dxe
PLIST_SUB+=	DE="@comment " DRAW="@comment " OCAF="@comment "
. endif
.else
CONFIGURE_ARGS+=--disable-vis --without-tcl --disable-draw --disable-dxe --disable-caf
PLIST_SUB+=	VIS="@comment " DRAW="@comment " DE="@comment " OCAF="@comment "
.endif

.if ${PORT_OPTIONS:MFI}
LIB_DEPENDS+=	libfreeimageplus.so:${PORTSDIR}/graphics/freeimage
CONFIGURE_ARGS+=--with-freeimage=${LOCALBASE}
.else
PLIST_SUB+=	FI="@comment "
.endif

.if ${PORT_OPTIONS:MQT}
USE_QT4=	corelib gui
CONFIGURE_ARGS+=--with-qt=${LOCALBASE}
LDFLAGS+=	-L${QT_LIBDIR}
.else
PLIST_SUB+=	QT="@comment "
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
CONFIGURE_ARGS+=--with-java-include=${JAVA_HOME}/include
.else
CONFIGURE_ARGS+=--without-java-include
PLIST_SUB+=	JAVA="@comment "
.endif

.if ${PORT_OPTIONS:MDATA}
PORTDATA=	*
.endif
.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

F_MALLOC=	OSD/OSD_signal_WNT.cxx OSD/OSD_Csharedmemory.c OSD/OSD_MemInfo.cxx	\
		OSD/OSD_Thread.cxx OSD/OSD.cxx OSD/OSD_SharedLibrary.cxx		\
		OSD/OSD_MemInfo.cxx MMgt/MMgt_StackManager.cxx Image/Image_PixMap.cxx	\
		Standard/Standard_MMgrOpt.cxx Standard/Standard.cxx StepFile/step.yacc	\
		StepFile/recfile.pc ExprIntrp/ExprIntrp.tab.c

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: to build OpenCascade, you should have at least"
	@${ECHO_MSG} "2.6 Gb of free disk space in build area!"
	@${ECHO_MSG}

pre-configure:
.if ${PORT_OPTIONS:MQT}
	${REINPLACE_CMD} -e 's|$$qt/include|${QT_INCDIR}|g' ${WRKSRC}/configure.ac
.endif
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${F_MALLOC:C|^|${WRKSRC}/src/|}

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/OpenCASCADE
	${RM} -f ${OCCROOT}/src/OS/*.orig ${OCCROOT}/src/DrawResources/*.orig	\
		${PREFIX}/include/OpenCASCADE/Standard_CLocaleSentry.hxx.orig
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} UnitsAPI ${OCCROOT}/src
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${DATADIR}
. for dir in data tests
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR}
. endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	${MKDIR} /tmp/testOCC
	bash -c "\
	cd ${OCCROOT} && . ${OCCROOT}/env_amk.sh &&	\
	CSF_TestScriptsPath=${DATADIR}/tests	\
	CSF_TestDataPath=${DATADIR}/data	\
	DRAWEXE -f ${FILESDIR}/regtest "
.endif

.include <bsd.port.mk>
