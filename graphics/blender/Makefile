# Created by: Jimmy Olgeni <olgeni@uli.it>
# $FreeBSD$

PORTNAME=	blender
DISTVERSION=	2.82
PORTREVISION=	5
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	3D modeling/rendering/animation package

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/doc/license/GPL3-license.txt

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	${PYNUMPY}
# libboost_regex.so just acts as a placeholder; several boost
# libraries are used, if either of the most common options in blender
# are set. We will pull boost in just to be on the safe side.

USES=		cmake compiler:c++14-lang gl jpeg python:3.7 shebangfix \
		tar:xz xorg
USE_XORG=	x11 xext xfixes xmu xrender
USE_GL=		gl glu glew

INSTALLS_ICONS=	yes
CMAKE_OFF=	WITH_IMAGE_OPENJPEG WITH_PYTHON_INSTALL \
		WITH_PYTHON_INSTALL_NUMPY WITH_INSTALL_PORTABLE \
		WITH_CYCLES_LOGGING

SHEBANG_FILES=	release/bin/blender-thumbnailer.py \
		release/scripts/modules/bl_i18n_utils/merge_po.py \
		release/scripts/modules/bl_i18n_utils/utils_rtl.py \
		release/scripts/modules/blend_render_info.py
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-float-conversion
CFLAGS_i386=	-march=i586
CXXFLAGS_i386=	-march=i586
# Use LLVM linker where available
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
LDFLAGS+=	-fuse-ld=lld
.endif

# version without trailing update letters
VERDIR=		${DISTVERSION:C/[abcdef]//g}
PLIST_SUB+=	VER=${VERDIR}
LLVM_VER=	90
OPTIONS_SUB=	yes

.include "${.CURDIR}/Makefile.options"

ALEMBIC_CMAKE_BOOL=		WITH_ALEMBIC
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic
# note that this needs to be set to match alembics hdf5 option
ALEMBIC_HDF5_REQUIRES=		ALEMBIC
ALEMBIC_HDF5_CMAKE_BOOL=	WITH_ALEMBIC_HDF5
ALEMBIC_HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
AVI_CMAKE_BOOL=			WITH_CODEC_AVI
BULLET_CMAKE_BOOL=		WITH_BULLET
CAMERATRACK_CMAKE_BOOL=		WITH_LIBMV
CAMERATRACK_LIB_DEPENDS=	libunwind.so:devel/libunwind
CAMERATRACK_ONLY_FOR_ARCHS=	i386 amd64
CAMERATRACK_ONLY_FOR_ARCHS_REASON=	libunwind only supports x86/amd64
CINEON_CMAKE_BOOL=		WITH_IMAGE_CINEON
COLLADA_CMAKE_BOOL=		WITH_OPENCOLLADA
COLLADA_LIB_DEPENDS=		libOpenCOLLADABaseUtils.so:graphics/opencollada \
				libpcre.so:devel/pcre
COLLADA_USE=			GNOME=libxml2
COLLADA_USES=			gnome
COMPOSITOR_CMAKE_BOOL=		WITH_COMPOSITOR
CYCLES_IMPLIES=			OPENIMAGEIO
CYCLES_CMAKE_BOOL=		WITH_CYCLES
CYCLESEMBR_IMPLIES=		CYCLES
CYCLESEMBR_CMAKE_BOOL=		WITH_CYCLES_EMBREE
CYCLESEMBR_LIB_DEPENDS=		libembree3.so:graphics/embree
CYCLESEMBR_ONLY_FOR_ARCHS=	amd64
CYCLESEMBR_ONLY_FOR_ARCHS_REASON=	embree only supports amd64
CYCLESOSL_IMPLIES=		CYCLES
CYCLESOSL_CMAKE_BOOL=		WITH_CYCLES_OSL WITH_LLVM
CYCLESOSL_CMAKE_ON=		-DLLVM_STATIC:BOOL=OFF \
				-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VER}"
CYCLESOSL_BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
CYCLESOSL_LIB_DEPENDS=		liboslcomp.so:graphics/openshadinglanguage
CYCLESOSL_RUN_DEPENDS=		llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
DDS_CMAKE_BOOL=			WITH_IMAGE_DDS
DRACO_CMAKE_BOOL=		WITH_DRACO
DRACO_USE=			LDCONFIG=${PYTHON_SITELIBDIR}
FFMPEG_CMAKE_BOOL=		WITH_CODEC_FFMPEG
FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg
FFTW3_CMAKE_BOOL=		WITH_FFTW3
FFTW3_LIB_DEPENDS=		libfftw3.so:math/fftw3
FRAMESERVER_CMAKE_BOOL=		WITH_IMAGE_FRAMESERVER
FREESTYLE_CMAKE_BOOL=		WITH_FREESTYLE
HDR_CMAKE_BOOL=			WITH_IMAGE_HDR
HEADLESS_PREVENTS=		MENU XINPUT XF86VMODE
HEADLESS_PREVENTS_MSG=		X11 options can't be used in headless mode
HEADLESS_CMAKE_BOOL=		WITH_HEADLESS
INPUT_NDOF_CMAKE_BOOL=		WITH_INPUT_NDOF
JACK_CMAKE_BOOL=		WITH_JACK
JACK_LIB_DEPENDS=		libjack.so:audio/jack
LZO_CMAKE_BOOL=			WITH_LZO
LZMA_CMAKE_BOOL=		WITH_LZMA
MENU_USES=			desktop-file-utils
MOD_BOOLEAN_CMAKE_BOOL=		WITH_MOD_BOOLEAN
MOD_FLUID_CMAKE_BOOL=		WITH_MOD_FLUID
MOD_OCEANSIM_IMPLIES=		FFTW3
MOD_OCEANSIM_CMAKE_BOOL=	WITH_MOD_OCEANSIM
MOD_REMESH_CMAKE_BOOL=		WITH_MOD_REMESH
MOD_SMOKE_CMAKE_BOOL=		WITH_MOD_SMOKE
NLS_CMAKE_BOOL=			WITH_INTERNATIONAL
# Use iconv:wchar_t to force the usage of iconv from ports.
# libboost_locale.so uses libiconv_open, while we only provide
# iconv_open in 10.x+
NLS_USES=			gettext iconv:lib,wchar_t
OPENAL_CMAKE_BOOL=		WITH_OPENAL
OPENAL_USES=			openal:al,alut
OPENCOLORIO_CMAKE_BOOL=		WITH_OPENCOLORIO
OPENCOLORIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
				libyaml-cpp03.so:devel/yaml-cpp03 \
				libtinyxml.so:textproc/tinyxml
OPENEXR_CMAKE_BOOL=		WITH_IMAGE_OPENEXR
OPENEXR_LIB_DEPENDS=		libIlmImf.so:graphics/openexr \
				libHalf.so:graphics/ilmbase
OPENIMAGEIO_IMPLIES=		OPENEXR TIFF
OPENIMAGEIO_CMAKE_BOOL=		WITH_OPENIMAGEIO
OPENIMAGEIO_LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio
OPENIMAGEDN_CMAKE_BOOL=		WITH_OPENIMAGEDENOISE
OPENIMAGEDN_LIB_DEPENDS=	libOpenImageDenoise.so:graphics/oidn
OPENIMAGEDN_ONLY_FOR_ARCHS=	amd64
OPENIMAGEDN_ONLY_FOR_ARCHS_REASON=	oidn only supports amd64
# openmp usually works on amd64
OPENMP_CMAKE_BOOL=		WITH_OPENMP
OPENSUBDIV_CMAKE_BOOL=		WITH_OPENSUBDIV
OPENSUBDIV_LIB_DEPENDS=		libosdCPU.so:graphics/opensubdiv
OPENVDB_CMAKE_BOOL=		WITH_OPENVDB WITH_OPENVDB_BLOSC
OPENVDB_LIB_DEPENDS=		libblosc.so:archivers/c-blosc \
				libopenvdb.so:misc/openvdb \
				libtbb.so:devel/tbb
RAYOPTIMIZATION_CMAKE_BOOL=	WITH_RAYOPTIMIZATION
SDL_CMAKE_BOOL=			WITH_SDL
SDL_USE=			SDL=sdl2
SDL_USES=			sdl
SNDFILE_CMAKE_BOOL=		WITH_CODEC_SNDFILE
SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
TBB_CMAKE_BOOL=			WITH_TBB
TBB_LIB_DEPENDS=		libtbb.so:devel/tbb
TIFF_CMAKE_BOOL=		WITH_IMAGE_TIFF
TIFF_LIB_DEPENDS=		libtiff.so:graphics/tiff
XINPUT_CMAKE_BOOL=		WITH_X11_XINPUT
XINPUT_USE=			XORG=xi
XF86VMODE_CMAKE_BOOL=		WITH_X11_XF86VMODE
XF86VMODE_USE=			XORG=xi,xxf86vm

.if defined(WITH_DEBUG)
CMAKE_ARGS+=		-DWITH_GHOST_DEBUG:BOOL=ON
.endif

post-patch-OPENCOLORIO-on:
	@${REINPLACE_CMD} -e 's|yaml-cpp|&03|' \
		${PATCH_WRKSRC}/build_files/cmake/Modules/FindOpenColorIO.cmake

post-build:
	@(cd ${WRKSRC}/doc/manpage && \
		${PYTHON_CMD} blender.1.py \
			${INSTALL_WRKSRC}/bin/blender \
			${INSTALL_WRKSRC}/bin/${PORTNAME}.1)

post-install:
	${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DRACO-on:
	# move draco pylib into site-packages
	${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}/
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/libextern_draco.so ${STAGEDIR}/${PYTHON_SITELIBDIR}/
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/libextern_draco.so
	@${RM} -R ${STAGEDIR}/${PREFIX}/share/blender/${VERDIR}/python

post-install-MENU-on:
	@-update-desktop-database -q

.include <bsd.port.mk>
