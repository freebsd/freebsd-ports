# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	opencascade
PORTVERSION=	7.2.0
PORTREVISION=	2
CATEGORIES=	cad science
MASTER_SITES=	LOCAL/thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

LICENSE=	OCTPL
LICENSE_NAME=	LGPL21 with exception
LICENSE_FILE=	${WRKSRC}/OCCT_LGPL_EXCEPTION.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2	\
		libtbb.so:devel/tbb		\
		libvtksys-${VTKVER}.so:math/vtk6
RUN_DEPENDS=	bash:shells/bash

# Check ${WRKSRC}/dox/overview/overview.md
# and ${WRKSRC}/dox/dev_guides/building
USES=		alias:10 cmake:outsource compiler:c++14-lang dos2unix \
		shebangfix tk tar:tgz
USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu
DOS2UNIX_FILES=	adm/templates/*
SHEBANG_FILES=	adm/templates/*.sh	\
		adm/templates/*.sh.in	\
		adm/templates/*.sh.main	\
		gendoc
ENVSH=		env.sh adm/templates/env.sh.in adm/templates/env.sh
VTKVER=		6.2

OPTIONS_DEFINE=	DOCS DOXYGEN FFMPEG VIS
VIS_DESC=	Build Visualizazion module (requires OpenGL, freetype, ftgl and gl2ps)
OPTIONS_DEFAULT=FFMPEG VIS
OPTIONS_SUB=	yes

REINPLACE_ARGS=	-i ""
CFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS+=	-DINSTALL_DIR=${OCCROOT}				\
		-DINSTALL_DIR_INCLUDE=${PREFIX}/include/OpenCASCADE	\
		-DINSTALL_DIR_LIB=${PREFIX}/lib				\
		-DINSTALL_DIR_CMAKE=${PREFIX}/lib/cmake			\
		-DINSTALL_DIR_DATA=${OCCROOT}/data			\
		-DINSTALL_DIR_RESOURCE=${OCCROOT}/resources		\
		-DINSTALL_DIR_SAMPLES=${OCCROOT}/samples		\
		-DINSTALL_DIR_TESTS=${OCCROOT}/tests			\
		-DINSTALL_TEST_CASES:BOOL=ON				\
		-DUSE_TBB:BOOL=ON					\
		-DUSE_VTK:BOOL=ON

USE_LDCONFIG=	yes

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}" BITS=${BITS} CC=${CHOSEN_COMPILER_TYPE}	\
		VE=${PORTVERSION:R:R} VER=${PORTVERSION}

FFMPEG_CMAKE_ON=	-DUSE_FFMPEG:BOOL=ON
FFMPEG_CMAKE_OFF=	-DUSE_FFMPEG:BOOL=OFF
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

VIS_CMAKE_ON=		-DUSE_FREEIMAGE:BOOL=ON -DUSE_GL2PS:BOOL=ON	\
			-DUSE_FREETYPE:BOOL=ON
VIS_CMAKE_OFF=		-DUSE_FREEIMAGE:BOOL=OFF -DUSE_GL2PS:BOOL=OFF	\
			-DUSE_FREETYPE:BOOL=OFF
VIS_LIB_DEPENDS=	libftgl.so:graphics/ftgl		\
			libgl2ps.so:print/gl2ps		\
			libfreeimageplus.so:graphics/freeimage

VIS_CMAKE_ON=	-D3RDPARTY_FREETYPE_DIR=${LOCALBASE}

DOXYGEN_USE=	TEX=latex:build
DOXYGEN_BUILD_DEPENDS=	bash:shells/bash		\
			doxygen:devel/doxygen		\
			dot:graphics/graphviz		\
			inkscape:graphics/inkscape
DOXYGEN_RUN_DEPENDS=	${LOCALBASE}/www/MathJax/MathJax.js:www/mathjax

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1003506
# undefined reference to `__cxa_thread_atexit' - see PR 192320
BROKEN=	undefined reference to __cxa_thread_atexit
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
.for es in ${ENVSH}
	${REINPLACE_CMD} -e 's|lin|bsd|;s|x86_64|amd64|' ${WRKSRC}/${es}
.endfor

pre-patch:
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/src/OSD/OSD_MemInfo.cxx \
		${WRKSRC}/src/StepFile/step.tab.c \
		${WRKSRC}/src/StepFile/step.yacc

post-build-DOXYGEN-on:
	(cd ${WRKSRC} && ./gendoc -overview)

post-install:
	${MV} ${STAGEDIR}${OCCROOT}/bin/DRAWEXE-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/DRAWEXE
	(cd ${STAGEDIR}${PREFIX}/bin &&							\
	${LN} -sf DRAWEXE ${STAGEDIR}${OCCROOT}/bin/DRAWEXE)
post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/overview && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${RM} -r ${STAGEDIR}${DOCSDIR}/latex

.if defined(MAINTAINER_MODE)
regression-test:	install
	${RM} -rf /tmp/testOCC
	${MKDIR} /tmp/testOCC
	bash -c "\
	cd ${OCCROOT} && . ${OCCROOT}/bin/env.sh &&	\
	CSF_TestScriptsPath=${OCCROOT}/tests		\
	CSF_TestDataPath=${OCCROOT}/data		\
	DRAWEXE -f ${FILESDIR}/regtest "
.endif

.include <bsd.port.mk>
