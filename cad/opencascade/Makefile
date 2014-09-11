# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	opencascade
PORTVERSION=	6.7.1
PORTREVISION=	2
CATEGORIES=	cad science
MASTER_SITES=	http://files.opencascade.com/OCCT/OCC_${PORTVERSION}_release/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

LICENSE=	OCTPL
LICENSE_NAME=	LGPL21 with exception
LICENSE_FILE=	${WRKSRC}/OCCT_LGPL_EXCEPTION.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

# Check ${WRKSRC}/dox/overview/Overview.md
# and ${WRKSRC}/dox/dev_guides/building
USES=		bison cmake compiler dos2unix gmake shebangfix tk tar:tgz
USE_XORG=	xmu
DOS2UNIX_FILES=	adm/templates/*
SHEBANG_FILES=	adm/templates/env.sh.in adm/templates/draw.sh		\
		adm/templates/custom.sh.in adm/templates/custom.sh.main	\
		adm/start.tcl draw.sh xcode.sh env.sh custom.sh.in	\
		gendoc codeblocks.sh

OPTIONS_DEFINE=	TBB VIS DOCS
TBB_DESC=	Build with TBB
VIS_DESC=	Build Visualizazion module (requires OpenGL, freetype, ftgl and gl2ps)
OPTIONS_DEFAULT=TBB VIS
OPTIONS_SUB=	yes

REINPLACE_ARGS=	-i ""
CFLAGS+=	-I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${TCL_LIBDIR} -L${TK_LIBDIR}
CMAKE_ARGS+=	-D3RDPARTY_TCL_INCLUDE_DIR=${TCL_INCLUDEDIR}	\
		-D3RDPARTY_TCL_LIBRARY=${TCL_LIBDIR}		\
		-D3RDPARTY_TCL_DLL=libtcl${TCL_VER:C|\.||}	\
		-DINSTALL_DIR=${OCCROOT}/
USE_LDCONFIG=	yes

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}" BITS=${BITS} CC=${COMPILER_TYPE}

TBB_LIB_DEPENDS=	libtbb.so:${PORTSDIR}/devel/tbb
TBB_CMAKE_ON=		-DUSE_TBB:BOOL=ON

VIS_CMAKE_ON=		-DUSE_FREEIMAGE:BOOL=ON -DUSE_GL2PS:BOOL=ON
VIS_USE=		GL=glu
VIS_LIB_DEPENDS=	libftgl.so:${PORTSDIR}/graphics/ftgl		\
			libfreetype.so:${PORTSDIR}/print/freetype2	\
			libgl2ps.so:${PORTSDIR}/print/gl2ps		\
			libfreeimageplus.so:${PORTSDIR}/graphics/freeimage

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIS}
CMAKE_ARGS+=	-D3RDPARTY_FREETYPE_DIR=${LOCALBASE}	\
		-D3RDPARTY_FREEIMAGE_DIR=${LOCALBASE}	\
		-D3RDPARTY_GL2PS_DIR=${LOCALBASE}	\
		-D3RDPARTY_TBB_DIR=${LOCALBASE}		\
		-D3RDPARTY_TBB_DLL=${LOCALBASE}/lib	\
		-D3RDPARTY_TBB_MALLOC_DLL=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX+=	latex:build
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash		\
		doxygen:${PORTSDIR}/devel/doxygen	\
		dot:${PORTSDIR}/graphics/graphviz	\
		inkscape:${PORTSDIR}/graphics/inkscape
RUN_DEPENDS+=	${LOCALBASE}/www/MathJax/MathJax.js:${PORTSDIR}/www/mathjax
.endif

.if ${ARCH} == "i386"
BITS=	32
.else
BITS=	64
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: to build OpenCascade, you should have at least"
	@${ECHO_MSG} "2.6 Gb of free disk space in build area!"
	@${ECHO_MSG}

pre-configure:
	${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|' ${WRKSRC}/gendoc
.for mod in TKDraw TKViewerTest
	${REINPLACE_CMD} -e 's|tcl8.6|tcl${TCL_VER:C|\.||}|;s|tk8.6|tk${TK_VER:C|\.||}|'	\
		${WRKSRC}/adm/cmake/${mod}/CMakeLists.txt
.endfor
.for es in env.sh adm/templates/env.sh.in
	${REINPLACE_CMD} -e 's|lin|bsd|' ${WRKSRC}/${es}
.endfor

post-build:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} && ./gendoc -overview)
.endif

post-install:
	${MV} ${STAGEDIR}${OCCROOT}/bsd${BITS}/${COMPILER_TYPE}/bin/DRAWEXE	\
		${STAGEDIR}${PREFIX}/bin/
	(cd ${STAGEDIR}${PREFIX}/bin &&							\
	${LN} -sf DRAWEXE ${STAGEDIR}${OCCROOT}/bsd${BITS}/${COMPILER_TYPE}/bin/DRAWEXE)
	${MV} ${STAGEDIR}${OCCROOT}/bsd${BITS}/${COMPILER_TYPE}/lib/lib*.so	\
		${STAGEDIR}${PREFIX}/lib/
	(cd ${STAGEDIR}${PREFIX}/lib							\
	&& for l in lib*.so; do								\
	${MV} $${l} $${l}.0;								\
	${LN} -sf $${l}.0 $${l};							\
	${LN} -sf $${l}.0 ${STAGEDIR}${OCCROOT}/bsd${BITS}/${COMPILER_TYPE}/lib/$${l};	\
	done)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/OpenCASCADE
	(cd ${STAGEDIR}${OCCROOT}/inc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/OpenCASCADE)
	${RM} -rf ${STAGEDIR}${OCCROOT}/inc
	${MKDIR} ${STAGEDIR}${OCCROOT}/inc
	(cd ${STAGEDIR}${PREFIX}/include/OpenCASCADE		\
	&& for i in *; do					\
	${LN} -sf $${i} ${STAGEDIR}${OCCROOT}/inc/$${i};	\
	done)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tests ${STAGEDIR}${OCCROOT})
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/overview && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${RMDIR} ${STAGEDIR}${DOCSDIR}/latex
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	${MKDIR} /tmp/testOCC
	bash -c "\
	cd ${OCCROOT} && . ${OCCROOT}/env.sh &&	\
	CSF_TestScriptsPath=${OCCROOT}/tests	\
	CSF_TestDataPath=${OCCROOT}/data	\
	DRAWEXE -f ${FILESDIR}/regtest "
.endif

.include <bsd.port.mk>
