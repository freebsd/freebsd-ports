# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	opencascade
PORTVERSION=	7.5.0
PORTREVISION=	1
CATEGORIES=	cad science
MASTER_SITES=	LOCAL/thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation

LICENSE=	OCTPL
LICENSE_NAME=	LGPL21 with exception
LICENSE_FILE=	${WRKSRC}/OCCT_LGPL_EXCEPTION.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson			\
		${LOCALBASE}/lib/qt5/bin/qmake:devel/qt5-qmake	\
		${LOCALBASE}/lib/qt5/bin/moc:devel/qt5-buildtools
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
		libvtksys-${VTKVER}.so:math/vtk8	\
		libfreetype.so:print/freetype2
RUN_DEPENDS=	bash:shells/bash

# Check ${WRKSRC}/dox/overview/overview.md
# and ${WRKSRC}/dox/dev_guides/building
USES=		alias:10 cmake compiler:c++14-lang dos2unix \
		gl python qt:5 shebangfix tk tar:tgz xorg
USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu

DOS2UNIX_FILES=	adm/templates/*
SHEBANG_FILES=	adm/templates/*.sh	\
		adm/templates/*.sh.in	\
		adm/templates/*.sh.main	\
		adm/genconf.tcl		\
		adm/start.tcl		\
		gendoc
ENVSH=		adm/templates/env.sh

VTKVER=		8.2

OPTIONS_DEFINE=	DOCS DOXYGEN FFMPEG VIS
VIS_DESC=	Build Visualizazion module (requires OpenGL, freetype, ftgl)
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
		-DUSE_TBB:BOOL=OFF					\
		-DUSE_RAPIDJSON:BOOL=ON					\
		-DUSE_VTK:BOOL=ON					\
		-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTKVER}/cmake/vtk-${VTKVER}

# TODO: TBB to be replaced by onetbb later
#CMAKE_ARGS+=	-DUSE_EIGEN:BOOL=ON -DUSE_TBB:BOOL=ON
#USES+=		eigen:3
#LIB_DEPENDS+=	libtbb.so:devel/tbb

USE_LDCONFIG=	yes

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}" BITS=${BITS} CC=${CHOSEN_COMPILER_TYPE}	\
		VE=${PORTVERSION:R:R} VER=${PORTVERSION}

FFMPEG_CMAKE_ON=	-DUSE_FFMPEG:BOOL=ON
FFMPEG_CMAKE_OFF=	-DUSE_FFMPEG:BOOL=OFF
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

VIS_CMAKE_ON=		-DUSE_FREEIMAGE:BOOL=ON	\
			-DUSE_FREETYPE:BOOL=ON	\
			-DUSE_GLES2:BOOL=ON	\
			-D3RDPARTY_FREETYPE_DIR=${LOCALBASE}
VIS_CMAKE_OFF=		-DUSE_FREEIMAGE:BOOL=OFF	\
			-DUSE_FREETYPE:BOOL=OFF		\
			-DUSE_GLES2:BOOL=OFF
VIS_LIB_DEPENDS=	libftgl.so:graphics/ftgl	\
			libfreeimageplus.so:graphics/freeimage
VIS_USE=		GL=glesv2

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_USE=	TEX=latex:build
DOXYGEN_BUILD_DEPENDS=	bash:shells/bash		\
			doxygen:devel/doxygen		\
			dot:graphics/graphviz		\
			pdftex:print/tex-basic-engines	\
			inkscape:graphics/inkscape
DOXYGEN_RUN_DEPENDS=	${LOCALBASE}/www/MathJax/MathJax.js:www/mathjax

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

pre-patch:
	${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/src/BRepMesh/delabella.cpp\
		${WRKSRC}/src/OSD/OSD_MemInfo.cxx

pre-configure:
	${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|' ${WRKSRC}/gendoc
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|' ${WRKSRC}/adm/genconfdeps.tcl
	${GREP} -rl x86_64 ${WRKSRC} | ${XARGS} ${REINPLACE_CMD}	\
		-e 's|x86_64|amd64|'
.for es in ${ENVSH}
	${REINPLACE_CMD} -e 's|lin|bsd|' ${WRKSRC}/${es}
.endfor

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
	${RM} ${STAGEDIR}${DOCSDIR}/html/build_upgrade_building_3rdparty.html.bak

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
