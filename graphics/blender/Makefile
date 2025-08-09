PORTNAME=	blender
DISTVERSION=	4.2.0
PORTREVISION=	12
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

PATCH_SITES=	https://projects.blender.org/blender/blender/commit/
PATCHFILES=	1c69154aaf033730a9e3882574d56ca6597b84ae.patch:-p1

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	3D modeling/rendering/animation package
WWW=		https://www.blender.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/doc/license/GPL3-license.txt

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	static_assert(sizeof(unsigned long long) == sizeof(struct hipArray*))

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libepoxy.so:graphics/libepoxy \
		libOpenImageIO.so:graphics/openimageio \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYNUMPY}
# libboost_regex.so just acts as a placeholder; several boost
# libraries are used, if either of the most common options in blender
# are set. We will pull boost in just to be on the safe side.
USES=		cmake:noninja compiler:c++17-lang cpe eigen:3 jpeg llvm:build,run pkgconfig \
		python:3.11 shebangfix tar:xz xorg
USE_XORG=	x11 xext xfixes xmu xrender

SHEBANG_FILES=	scripts/modules/bl_i18n_utils/merge_po.py \
		scripts/modules/bl_i18n_utils/utils_rtl.py \
		scripts/modules/blend_render_info.py

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD:INTEGER=17 \
		-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VERSION}"
.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DWITH_GHOST_DEBUG:BOOL=ON
.endif
CMAKE_ON=	WITH_AUDASPACE WITH_BOOST WITH_CLANG WITH_GHOST_X11 WITH_GHOST_XDND \
		WITH_HYDRA WITH_IO_GPENCIL WITH_IO_PLY WITH_IO_STL WITH_IO_WAVEFRONT_OBJ \
		WITH_LLVM WITH_OPENGL_BACKEND WITH_PYTHON WITH_SYSTEM_EIGEN3 \
		WITH_SYSTEM_FREETYPE WITH_X11_XINPUT WITH_X11_XF86VMODE WITH_X11_XFIXES
CMAKE_OFF=	WITH_GHOST_SDL WITH_INSTALL_PORTABLE LLVM_STATIC WITH_MATERIALX \
		WITH_MEM_JEMALLOC WITH_MEM_VALGRIND WITH_NANOVDB WITH_PYTHON_INSTALL \
		WITH_PYTHON_INSTALL_NUMPY

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-float-conversion
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lexecinfo -Wl,--undefined-version

SUB_FILES=	blender
PLIST_SUB+=	VER=${DISTVERSION:R}
OPTIONS_SUB=	yes

.include "${.CURDIR}/Makefile.options"

ALEMBIC_IMPLIES=		OPENEXR
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic
ALEMBIC_CMAKE_BOOL=		WITH_ALEMBIC
AVI_CMAKE_BOOL=			WITH_CODEC_AVI
BULLET_CMAKE_BOOL=		WITH_BULLET
CAMERATRACK_LIB_DEPENDS=	libglog.so:devel/glog
CAMERATRACK_CMAKE_BOOL=		WITH_LIBMV WITH_SYSTEM_GLOG
CINEON_CMAKE_BOOL=		WITH_IMAGE_CINEON
COLLADA_LIB_DEPENDS=		libOpenCOLLADABaseUtils.so:graphics/opencollada \
				libpcre.so:devel/pcre
COLLADA_USES=			gnome
COLLADA_USE=			GNOME=libxml2
COLLADA_CMAKE_BOOL=		WITH_OPENCOLLADA
COMPOSITOR_CMAKE_BOOL=		WITH_COMPOSITOR_CPU
CYCLES_IMPLIES=			TBB
CYCLES_LIB_DEPENDS=		libgflags.so:devel/gflags
CYCLES_CMAKE_BOOL=		WITH_CYCLES WITH_CYCLES_LOGGING
CYCLES_LDFLAGS=			-L${LOCALBASE}/lib -lgflags
CYCLES_EMBR_IMPLIES=		CYCLES
CYCLES_EMBR_LIB_DEPENDS=	libembree3.so:graphics/embree3
CYCLES_EMBR_CMAKE_BOOL=		WITH_CYCLES_EMBREE
CYCLES_ONEAPI_LIB_DEPENDS=	libtbb.so:devel/onetbb
CYCLES_ONEAPI_CMAKE_BOOL=	WITH_CYCLES_DEVICE_ONEAPI
CYCLES_OSL_IMPLIES=		CYCLES OPENEXR PUGIXML
CYCLES_OSL_LIB_DEPENDS=		liboslcomp.so:graphics/openshadinglanguage
CYCLES_OSL_CMAKE_BOOL=		WITH_CYCLES_OSL
CYCLES_OSL_CMAKE_ON=		-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"
DRACO_USE=			LDCONFIG=${PYTHON_SITELIBDIR}
DRACO_CMAKE_BOOL=		WITH_DRACO
EBOOL_LIB_DEPENDS=		libgmp.so:math/gmp
EBOOL_CMAKE_BOOL=		WITH_GMP
FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg \
				libflite.so:audio/flite
FFMPEG_CMAKE_BOOL=		WITH_CODEC_FFMPEG
FFMPEG_LDFLAGS=			-L${LOCALBASE}/lib -lflite -lflite_cmu_us_kal \
				-lflite_cmulex -lflite_usenglish
FFTW3_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libfftw3f.so:math/fftw3-float
FFTW3_CMAKE_BOOL=		WITH_FFTW3
FREESTYLE_CMAKE_BOOL=		WITH_FREESTYLE
FRIBIDI_LIB_DEPENDS=		libfribidi.so:converters/fribidi
FRIBIDI_CMAKE_BOOL=		WITH_FRIBIDI
HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
HARFBUZZ_CMAKE_BOOL=		WITH_HARFBUZZ
HARU_LIB_DEPENDS=		libhpdf.so:print/libharu
HARU_CMAKE_BOOL=		WITH_HARU
HEADLESS_PREVENTS=		MENU XINPUT XF86VMODE
HEADLESS_PREVENTS_MSG=		X11 options can't be used in headless mode
HEADLESS_CMAKE_BOOL=		WITH_HEADLESS
INPUT_NDOF_LIB_DEPENDS=		libspnav.so:misc/libspnav
INPUT_NDOF_CMAKE_BOOL=		WITH_INPUT_NDOF
JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CMAKE_BOOL=		WITH_JACK WITH_JACK_DYNLOAD
LZMA_CMAKE_BOOL=		WITH_LZMA
LZO_LIB_DEPENDS=		liblzo2.so:archivers/lzo2
LZO_CMAKE_BOOL=			WITH_LZO WITH_SYSTEM_LZO
MENU_USES=			desktop-file-utils
MOD_FLUID_IMPLIES=		TBB
MOD_FLUID_CMAKE_BOOL=		WITH_MOD_FLUID
MOD_OCEANSIM_IMPLIES=		FFTW3
MOD_OCEANSIM_CMAKE_BOOL=	WITH_MOD_OCEANSIM
MOD_REMESH_CMAKE_BOOL=		WITH_MOD_REMESH
# Use iconv:wchar_t to force the usage of iconv from ports.
# libboost_locale.so uses libiconv_open, while we only provide
# iconv_open in 10.x+
NLS_USES=			gettext-tools iconv:lib,wchar_t
NLS_CMAKE_BOOL=			WITH_INTERNATIONAL
OPENAL_USES=			openal:al,alut
OPENAL_CMAKE_BOOL=		WITH_OPENAL
OPENCOLORIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
				libyaml-cpp.so:devel/yaml-cpp \
				libexpat.so:textproc/expat2 \
				libpystring.so:devel/pystring
OPENCOLORIO_USES=		minizip
OPENCOLORIO_CMAKE_BOOL=		WITH_OPENCOLORIO
OPENEXR_LIB_DEPENDS=		libImath.so:math/Imath \
				libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL=		WITH_IMAGE_OPENEXR
OPENEXR_CFLAGS=			-I${LOCALBASE}/include/Imath
OPENIMAGEDN_IMPLIES=		TBB
OPENIMAGEDN_LIB_DEPENDS=	libOpenImageDenoise.so:graphics/oidn
OPENIMAGEDN_CMAKE_BOOL=		WITH_OPENIMAGEDENOISE
OPENJPEG_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
OPENJPEG_CMAKE_BOOL=		WITH_IMAGE_OPENJPEG
OPENMP_CMAKE_BOOL=		WITH_OPENMP
OPENPGL_LIB_DEPENDS=		libopenpgl.so:graphics/openpgl
OPENPGL_CMAKE_BOOL=		WITH_CYCLES_PATH_GUIDING
OPENSUBDIV_LIB_DEPENDS=		libosdCPU.so:graphics/opensubdiv
OPENSUBDIV_CMAKE_BOOL=		WITH_OPENSUBDIV
OPENVDB_IMPLIES=		OPENEXR TBB
OPENVDB_LIB_DEPENDS=		libopenvdb.so:misc/openvdb
OPENVDB_CMAKE_BOOL=		WITH_OPENVDB WITH_OPENVDB_BLOSC
OPENXR_LIB_DEPENDS=		libopenxr_loader.so:graphics/openxr
OPENXR_CMAKE_BOOL=		WITH_XR_OPENXR
POTRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
POTRACE_CMAKE_BOOL=		WITH_POTRACE
PUGIXML_LIB_DEPENDS=		libpugixml.so:textproc/pugixml
PUGIXML_CMAKE_BOOL=		WITH_PUGIXML
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=		WITH_PULSEAUDIO WITH_PULSEAUDIO_DYNLOAD
QUADRIFLOW_CMAKE_BOOL=		WITH_QUADRIFLOW
SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_CMAKE_BOOL=			WITH_SDL WITH_SDL_DYNLOAD
SIMD_CMAKE_BOOL=		WITH_CPU_SIMD
SIMD_EXTRA_PATCHES_OFF=		${PATCHDIR}/extra-patch-simd-off
SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=		WITH_CODEC_SNDFILE
TBB_LIB_DEPENDS=		libtbb.so:devel/onetbb
TBB_CMAKE_BOOL=			WITH_TBB
THUMBNAILER_CMAKE_BOOL=		WITH_BLENDER_THUMBNAILER
TRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
TRACE_CMAKE_BOOL=		WITH_POTRACE
USD_IMPLIES=			TBB
USD_BROKEN=			require devel/tbb, which conflicts with devel/onetbb: \
				https://github.com/PixarAnimationStudios/OpenUSD/issues/1650
USD_LIB_DEPENDS=		libusd_usd.so:misc/usd
USD_CMAKE_BOOL=			WITH_USD
VULKAN_BUILD_DEPENDS=		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=		libshaderc_shared.so:graphics/shaderc \
				libSPIRV-Tools-shared.so:graphics/spirv-tools \
				libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=		WITH_VULKAN_BACKEND
VULKAN_LDFLAGS=			-lshaderc_shared -lSPIRV-Tools-shared
WAYLAND_CATEGORIES=		wayland
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.15:graphics/wayland-protocols \
				wayland>=1.12:graphics/wayland \
				libdecor>0:x11-toolkits/libdecor
WAYLAND_LIB_DEPENDS=		libxkbcommon.so:x11/libxkbcommon
WAYLAND_CMAKE_BOOL=		WITH_GHOST_WAYLAND WITH_GHOST_WAYLAND_LIBDECOR \
				WITH_GHOST_WAYLAND_DYNLOAD
WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=		WITH_IMAGE_WEBP
XF86VMODE_USE=			XORG=xi,xxf86vm
XF86VMODE_CMAKE_BOOL=		WITH_X11_XF86VMODE
XINPUT_USE=			XORG=xi
XINPUT_CMAKE_BOOL=		WITH_X11_XINPUT

post-patch:
	${REINPLACE_CMD} -e 's|%%LLVM_VER%%|${LLVM_VERSION}|g' \
		${WRKSRC}/intern/cycles/kernel/osl/CMakeLists.txt

post-build:
	@(cd ${WRKSRC}/doc/manpage && \
		${PYTHON_CMD} blender.1.py \
			--blender ${INSTALL_WRKSRC}/bin/blender \
			--output ${INSTALL_WRKSRC}/bin/${PORTNAME}.1)

post-install:
	${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${MV} ${STAGEDIR}/${PREFIX}/bin/blender ${STAGEDIR}/${PREFIX}/bin/blender-bin
	${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' ${WRKDIR}/blender
	${INSTALL_SCRIPT} ${WRKDIR}/blender ${STAGEDIR}/${PREFIX}/bin/blender

post-install-DRACO-on:
	# move draco pylib into site-packages
	${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}/
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib/libextern_draco.so ${STAGEDIR}/${PYTHON_SITELIBDIR}/
	${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/libextern_draco.so
	@${RM} -R ${STAGEDIR}/${DATADIR}/${DISTVERSION:R}/python

post-install-MENU-on:
	@-update-desktop-database -q

.include <bsd.port.mk>
