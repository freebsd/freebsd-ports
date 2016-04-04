# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	opencascade
PORTVERSION=	6.9.1
PORTREVISION=	1
CATEGORIES=	cad science
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

LICENSE=	OCTPL
LICENSE_NAME=	LGPL21 with exception
LICENSE_FILE=	${WRKSRC}/OCCT_LGPL_EXCEPTION.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtbb.so:devel/tbb		\
		libvtksys-${VTKVER}.so:math/vtk6
RUN_DEPENDS=	bash:shells/bash

# Check ${WRKSRC}/dox/overview/Overview.md
# and ${WRKSRC}/dox/dev_guides/building
USES=		alias:10 bison cmake compiler dos2unix gmake shebangfix tk \
		tar:tgz
USE_XORG=	xmu
DOS2UNIX_FILES=	adm/templates/*
SHEBANG_FILES=	adm/templates/env.sh.in adm/templates/draw.sh		\
		adm/templates/custom.sh.in adm/templates/custom.sh.main	\
		adm/start.tcl draw.sh xcode.sh env.sh custom.sh.in	\
		gendoc codeblocks.sh
VTKVER=		6.2

OPTIONS_DEFINE=	VIS DOCS
VIS_DESC=	Build Visualizazion module (requires OpenGL, freetype, ftgl and gl2ps)
OPTIONS_DEFAULT=VIS
OPTIONS_SUB=	yes

REINPLACE_ARGS=	-i ""
CFLAGS+=	-I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${TCL_LIBDIR} -L${TK_LIBDIR}
CMAKE_ARGS+=	-D3RDPARTY_TCL_INCLUDE_DIR=${TCL_INCLUDEDIR}	\
		-D3RDPARTY_TCL_LIBRARY=${TCL_LIBDIR}		\
		-D3RDPARTY_TBB_DIR=${LOCALBASE}			\
		-D3RDPARTY_TBB_LIBRARY_DIR=${LOCALBASE}/lib	\
		-DINSTALL_DIR=${OCCROOT}/ -DUSE_TBB:BOOL=ON	\
		-D3RDPARTY_TBBMALLOC_LIBRARY=${LOCALBASE}/lib/libtbbmalloc.so	\
		-D3RDPARTY_TBB_LIBRARY=${LOCALBASE}/lib/libtbb.so	\
		-D3RDPARTY_TBBMALLOC_LIBRARY_DIR=${LOCALBASE}/lib	\
		-DUSE_VTK:BOOL=ON -D3RDPARTY_VTK_DIR=${LOCALBASE}	\
		-D3RDPARTY_VTK_INCLUDE_DIR=${LOCALBASE}/include/vtk-${VTKVER}	\
		-D3RDPARTY_VTK_LIBRARY_DIR=${LOCALBASE}/lib/vtk-${VTKVER}

USE_LDCONFIG=	yes

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}" BITS=${BITS} CC=${COMPILER_TYPE}

VIS_CMAKE_ON=		-DUSE_FREEIMAGE:BOOL=ON -DUSE_GL2PS:BOOL=ON	\
			-DUSE_FREETYPE:BOOL=ON
VIS_CMAKE_OFF=		-DUSE_FREEIMAGE:BOOL=OFF -DUSE_GL2PS:BOOL=OFF	\
			-DUSE_FREETYPE:BOOL=OFF
VIS_USE=		GL=glu
VIS_LIB_DEPENDS=	libftgl.so:graphics/ftgl		\
			libfreetype.so:print/freetype2	\
			libgl2ps.so:print/gl2ps		\
			libfreeimageplus.so:graphics/freeimage

VIS_CMAKE_ON=	-D3RDPARTY_FREETYPE_DIR=${LOCALBASE}	\
		-D3RDPARTY_FREEIMAGE_DIR=${LOCALBASE}	\
		-D3RDPARTY_GL2PS_DIR=${LOCALBASE}

DOCS_USE=	TEX=latex:build
DOCS_BUILD_DEPENDS=	bash:shells/bash		\
			doxygen:devel/doxygen	\
			dot:graphics/graphviz	\
			inkscape:graphics/inkscape
DOCS_RUN_DEPENDS=	${LOCALBASE}/www/MathJax/MathJax.js:www/mathjax

.include <bsd.port.options.mk>

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
.for mod in TKIVtk TKIVtkDraw
	${REINPLACE_CMD} -E 's/(vtk[[:alnum:]]+)\-6.1/\1\-${VTKVER}/'	\
		${WRKSRC}/adm/cmake/${mod}/CMakeLists.txt
.endfor
.for es in env.sh adm/templates/env.sh.in
	${REINPLACE_CMD} -e 's|lin|bsd|' ${WRKSRC}/${es}
.endfor

post-build-DOCS-on:
	(cd ${WRKSRC} && ./gendoc -overview)

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
	${LN} -sf ${PREFIX}/include/OpenCASCADE ${STAGEDIR}${OCCROOT}/inc
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tests ${STAGEDIR}${OCCROOT})
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/overview && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${RMDIR} ${STAGEDIR}${DOCSDIR}/latex

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
