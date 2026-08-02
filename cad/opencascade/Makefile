PORTNAME=	opencascade
DISTVERSIONPREFIX=	V
DISTVERSION=	8_0_1
CATEGORIES=	cad science
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open CASCADE Technology, 3D modeling & numerical simulation
WWW=		https://www.opencascade.org/

LICENSE=	OCTPL
LICENSE_NAME=	LGPL21 with exception
LICENSE_FILE=	${WRKSRC}/OCCT_LGPL_EXCEPTION.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson			\
		${LOCALBASE}/lib/qt5/bin/moc:devel/qt5-buildtools
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
		libfreetype.so:print/freetype2		\
		libtbbmalloc.so:devel/onetbb		\
		libexpat.so:textproc/expat2		\
		libdraco.so:archivers/draco		\
		libpng16.so:graphics/png		\
		libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R}
RUN_DEPENDS=	bash:shells/bash

# Check ${WRKSRC}/dox/build/build_occt/building_occt.md
USES=		cmake compiler:c++17-lang eigen:3 gettext-runtime	\
		gl gnome localbase python qmake:no_configure,no_env qt:5\
		shebangfix tk xorg
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xi xmu xrender xscrnsaver xt
USE_GL=		egl gl glesv2 glu
USE_GNOME=	libxml2
USE_QT=		buildtools:build core declarative gui network quick3d	\
		linguisttools widgets xml

USE_GITHUB=	yes
GH_ACCOUNT=	Open-Cascade-SAS
GH_PROJECT=	OCCT

SHEBANG_FILES=	adm/templates/*.sh	\
		adm/templates/*.sh.in	\
		adm/templates/*.sh.main	\
		adm/scripts/migration_800/*.py
ENVSH=		adm/templates/env.sh

OPTIONS_DEFINE=	DOCS DOXYGEN FFMPEG VIS
VIS_DESC=	Build Visualizazion module (requires OpenGL, freetype, ftgl)
OPTIONS_DEFAULT=FFMPEG VIS
OPTIONS_SUB=	yes

REINPLACE_ARGS=	-i ""
LDFLAGS+=	-Wl,--allow-shlib-undefined -lexecinfo
CMAKE_ARGS=	-DINSTALL_DIR:PATH=${OCCROOT}				\
		-DINSTALL_DIR_INCLUDE:PATH=${PREFIX}/include/OpenCASCADE	\
		-DINSTALL_DIR_LIB:PATH=${PREFIX}/lib				\
		-DINSTALL_DIR_CMAKE:PATH=${PREFIX}/lib/cmake			\
		-DINSTALL_DIR_DATA:PATH=${OCCROOT}/data			\
		-DINSTALL_DIR_RESOURCE:PATH=${OCCROOT}/resources		\
		-DINSTALL_DIR_TESTS:PATH=${OCCROOT}/tests			\
		-D3RDPARTY_QT_DIR:PATH=${LOCALBASE}/lib/cmake/Qt5	\
		-D3RDPARTY_DRACO_DIR:PATH=${LOCALBASE}			\
		-D3RDPARTY_DRACO_LIBRARY=libdraco.so			\
		-D3RDPARTY_DRACO_LIBRARY_DIR:PATH=${LOCALBASE}/lib	\
		-D3RDPARTY_DRACO_INCLUDE_DIR:PATH=${LOCALBASE}/include/draco	\
		-D3RDPARTY_VTK_INCLUDE_DIR:PATH=${LOCALBASE}/include/vtk-${VTK_VER}
CMAKE_ON=	CAN_USE_DRACO CAN_USE_EIGEN CAN_USE_FREETYPE CAN_USE_RAPIDJSON	\
		CAN_USE_TBB CAN_USE_TK CAN_USE_VTK CAN_USE_XLIB INSTALL_TEST_CASES\
		USE_DRACO USE_FREETYPE USE_RAPIDJSON USE_TBB USE_TCL USE_TK	\
		USE_VTK USE_XLIB
CONFIGURE_ENV+=	DESTDIR=${STAGEDIR}
USE_LDCONFIG=	yes

.if defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-DCMAKE_MESSAGE_CONTEXT_SHOW:BOOL=ON	\
		-DCMAKE_MESSAGE_LOG_LEVEL:STRING=DEBUG
.endif

CONFLICTS_INSTALL=	opencascade740 # OpenCAS/bin/DRAWEXE

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
PLIST_SUB=	OCCROOT="${LOCCROOT}" BITS=${BITS} CC=${CHOSEN_COMPILER_TYPE}	\
		VE=${PORTVERSION:R} VER=${PORTVERSION}

FFMPEG_CMAKE_ON=	-DCAN_USE_FFMPEG:BOOL=ON -DUSE_FFMPEG:BOOL=ON \
			-D3RDPARTY_FFMPEG_INCLUDE_DIR=${LOCALBASE}/ffmpeg6/include \
			-D3RDPARTY_FFMPEG_DIR=${LOCALBASE}/ffmpeg6
FFMPEG_CMAKE_OFF=	-DUSE_FFMPEG:BOOL=OFF
FFMPEG_LIB_DEPENDS=	libavcodec.so.60:multimedia/ffmpeg6	\
			libtheoraenc.so:multimedia/libtheora	\
			libunistring.so:devel/libunistring	\
			libvdpau.so:multimedia/libvdpau		\
			libxvidcore.so:multimedia/xvid		\
			libp11-kit.so:security/p11-kit		\
			libx264.so:multimedia/libx264		\
			libtasn1.so:security/libtasn1		\
			libvorbis.so:audio/libvorbis		\
			libdav1d.so:multimedia/dav1d		\
			libnettle.so:security/nettle		\
			libgnutls.so:security/gnutls		\
			libvpx.so:multimedia/libvpx		\
			libx265.so:multimedia/x265		\
			libdrm.so:graphics/libdrm		\
			libva.so:multimedia/libva		\
			libaom.so:multimedia/aom		\
			libmp3lame.so:audio/lame		\
			libffi.so:devel/libffi			\
			libidn2.so:dns/libidn2			\
			libogg.so:audio/libogg			\
			libopus.so:audio/opus			\
			libgmp.so:math/gmp

VIS_CMAKE_ON=		-DCAN_USE_FREEIMAGE:BOOL=ON -DUSE_FREEIMAGE:BOOL=ON	\
			-DCAN_USE_OPENGL:BOOL=ON -DUSE_OPENGL:BOOL=ON	\
			-DCAN_USE_GLES2:BOOL=ON -DUSE_GLES2:BOOL=ON	\
			-D3RDPARTY_FREETYPE_DIR=${LOCALBASE}
VIS_CMAKE_OFF=		-DUSE_FREEIMAGE:BOOL=OFF	\
			-DUSE_GLES2:BOOL=OFF
VIS_LIB_DEPENDS=	libftgl.so:graphics/ftgl	\
			libfreeimageplus.so:graphics/freeimage
VIS_USE=		GL=glesv2,opengl

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_USES=		tex
DOXYGEN_USE=		TEX=latex:build
DOXYGEN_BUILD_DEPENDS=	bash:shells/bash		\
			doxygen:devel/doxygen		\
			dot:graphics/graphviz		\
			pdftex:print/tex-basic-engines	\
			inkscape:graphics/inkscape
DOXYGEN_RUN_DEPENDS=	${LOCALBASE}/www/MathJax/MathJax.js:www/mathjax
DOXYGEN_CMAKE_ON=	-DBUILD_DOC_Overview:BOOL=ON	\
			-DINSTALL_DOC_Overview:BOOL=ON

.include <bsd.port.options.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == powerpc || ${ARCH} == powerpcspe || ${ARCH} == "i386"
BITS=	32
.else
BITS=	64
.endif

pre-configure:
	${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|'	\
		${WRKSRC}/src/ModelingAlgorithms/TKMesh/BRepMesh/delabella.cpp	\
		${WRKSRC}/src/FoundationClasses/TKernel/OSD/OSD_MemInfo.cxx
	${GREP} -rl x86_64 ${WRKSRC} | ${XARGS} ${REINPLACE_CMD}	\
		-e 's|x86_64|amd64|'
.for es in ${ENVSH}
	${REINPLACE_CMD} -e 's|lin|bsd|' ${WRKSRC}/${es}
.endfor

post-configure:
	${REINPLACE_CMD} -e '/Standard_Version.hxx/s|${BUILD_WRKSRC}/||'	\
		${BUILD_WRKSRC}/cmake_install.cmake

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/OpenCASCADE
	${MV} ${STAGEDIR}${PREFIX}/lib/cmake/*.cmake	\
		${STAGEDIR}${PREFIX}/lib/cmake/OpenCASCADE
.if defined(WITH_DEBUG)
	${FIND} ${STAGEDIR}${PREFIX}/lib/cmake/OpenCASCADE -name "*.cmake" |	\
		${XARGS} ${SED} -i '' -e 's/$${OCCT_INSTALL_BIN_LETTER}/d/'
.else
	${FIND} ${STAGEDIR}${PREFIX}/lib/cmake/OpenCASCADE -name "*.cmake" |	\
		${XARGS} ${SED} -i '' -e 's/$${OCCT_INSTALL_BIN_LETTER}//'
.endif
	${REINPLACE_CMD} -e '/Standard_Version.hxx/s|${STAGEDIR}${PREFIX}/||'	\
		-e '/^@dir/d' ${WRKDIR}/.PLIST.mktmp

post-install:
	${MV} ${STAGEDIR}${OCCROOT}/bin/DRAWEXE-${PORTVERSION}	\
		${STAGEDIR}${PREFIX}/bin/DRAWEXE
	${RLN} ${STAGEDIR}${PREFIX}/bin/DRAWEXE ${STAGEDIR}${OCCROOT}/bin

post-install-DOXYGEN-on:
	${RLN} ${STAGEDIR}${OCCROOT}/${DOCSDIR_REL} ${STAGEDIR}${DOCSDIR}

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

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
