PORTNAME=	blender
DISTVERSION=	5.0.1
PORTREVISION=	0
CATEGORIES=	graphics multimedia
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	3D modeling/rendering/animation package
WWW=		https://www.blender.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/doc/license/GPL3-license.txt

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	static_assert(sizeof(unsigned long long) == sizeof(struct hipArray*))

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libepoxy.so:graphics/libepoxy \
		libOpenImageIO.so:graphics/openimageio \
		libpng.so:graphics/png \
		libsamplerate.so:audio/libsamplerate \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake:noninja compiler:c++17-lang cpe eigen:3 jpeg llvm:build,run \
		pkgconfig python:3.11 shebangfix tar:xz xorg
USE_XORG=	x11 xext xfixes xmu xrender

SHEBANG_FILES=	scripts/modules/blend_render_info.py

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD:INTEGER=17 \
		-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VERSION}" \
		-DCMAKE_POLICY_DEFAULT_CMP0167=NEW
.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DWITH_GHOST_DEBUG:BOOL=ON
.endif
CMAKE_ON=	WITH_AUDASPACE WITH_BOOST WITH_CLANG WITH_GHOST_X11 WITH_GHOST_XDND \
		WITH_HYDRA WITH_IO_PLY WITH_IO_STL WITH_IO_WAVEFRONT_OBJ \
		WITH_LLVM WITH_OPENGL_BACKEND WITH_PYTHON WITH_SYSTEM_EIGEN3 \
		WITH_SYSTEM_FREETYPE WITH_X11_XINPUT WITH_X11_XFIXES
CMAKE_OFF=	WITH_GHOST_SDL WITH_INSTALL_PORTABLE WITH_LIBS_PRECOMPILED \
		LLVM_STATIC WITH_MEM_JEMALLOC WITH_MEM_VALGRIND \
		WITH_NANOVDB WITH_PYTHON_INSTALL WITH_PYTHON_INSTALL_NUMPY

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-float-conversion
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT
LDFLAGS+=	-lexecinfo -Wl,--undefined-version

SUB_FILES=	blender
PLIST_SUB+=	VER=${DISTVERSION:R}
OPTIONS_SUB=	yes

.include "${.CURDIR}/Makefile.options"

ALEMBIC_CMAKE_BOOL=		WITH_ALEMBIC
ALEMBIC_IMPLIES=		OPENEXR
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic
BULLET_CMAKE_BOOL=		WITH_BULLET
CAMERATRACK_CMAKE_BOOL=		WITH_LIBMV WITH_SYSTEM_GLOG
CAMERATRACK_LIB_DEPENDS=	libglog.so:devel/glog
CINEON_CMAKE_BOOL=		WITH_IMAGE_CINEON
CYCLES_CMAKE_BOOL=		WITH_CYCLES
CYCLES_IMPLIES=			TBB
CYCLES_LDFLAGS=			-L${LOCALBASE}/lib -lgflags
CYCLES_LIB_DEPENDS=		libgflags.so:devel/gflags
CYCLES_EMBR_CMAKE_BOOL=		WITH_CYCLES_EMBREE
CYCLES_EMBR_IMPLIES=		CYCLES
CYCLES_EMBR_LIB_DEPENDS=	libembree4.so:graphics/embree
CYCLES_ONEAPI_CMAKE_BOOL=	WITH_CYCLES_DEVICE_ONEAPI
CYCLES_ONEAPI_LIB_DEPENDS=	libtbb.so:devel/onetbb
CYCLES_OSL_CMAKE_BOOL=		WITH_CYCLES_OSL
CYCLES_OSL_CMAKE_ON=		-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"
CYCLES_OSL_IMPLIES=		CYCLES OPENEXR PUGIXML
CYCLES_OSL_LIB_DEPENDS=		liboslcomp.so:graphics/openshadinglanguage
DRACO_CMAKE_BOOL=		WITH_DRACO
DRACO_USE=			LDCONFIG=${PYTHON_SITELIBDIR}
EBOOL_CMAKE_BOOL=		WITH_GMP
EBOOL_LIB_DEPENDS=		libgmp.so:math/gmp
FFMPEG_CMAKE_BOOL=		WITH_CODEC_FFMPEG
FFMPEG_LDFLAGS=			-L${LOCALBASE}/lib -lflite -lflite_cmu_us_kal \
				-lflite_cmulex -lflite_usenglish
FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg \
				libflite.so:audio/flite
FFTW3_CMAKE_BOOL=		WITH_FFTW3
FFTW3_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libfftw3f.so:math/fftw3-float
FREESTYLE_CMAKE_BOOL=		WITH_FREESTYLE
FRIBIDI_CMAKE_BOOL=		WITH_FRIBIDI
FRIBIDI_LIB_DEPENDS=		libfribidi.so:converters/fribidi
HARFBUZZ_CMAKE_BOOL=		WITH_HARFBUZZ
HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
HARU_CMAKE_BOOL=		WITH_HARU
HARU_LIB_DEPENDS=		libhpdf.so:print/libharu
HEADLESS_CMAKE_BOOL=		WITH_HEADLESS
HEADLESS_PREVENTS=		MENU XINPUT XF86VMODE
HEADLESS_PREVENTS_MSG=		X11 options can't be used in headless mode
INPUT_NDOF_CMAKE_BOOL=		WITH_INPUT_NDOF
INPUT_NDOF_LIB_DEPENDS=		libspnav.so:misc/libspnav
JACK_CMAKE_BOOL=		WITH_JACK WITH_JACK_DYNLOAD
JACK_LIB_DEPENDS=		libjack.so:audio/jack
MANIFOLD_CMAKE_BOOL=		WITH_MANIFOLD
MANIFOLD_LIB_DEPENDS=		libmanifold.so:math/manifold
MATERIALX_CMAKE_BOOL=		WITH_MATERIALX
MATERIALX_CMAKE_ON=		-DMaterialX_DIR:STRING=${PREFIX}/lib/cmake/MaterialX \
				-DMATERIALX_STDLIB_DIR:STRING=${PREFIX}/share/materialx \
				-DMATERIALX_PYTHON_DIR:STRING=${PYTHON_SITELIBDIR}/MaterialX
MATERIALX_LIB_DEPENDS=		libMaterialXCore.so:graphics/materialx
MENU_USES=			desktop-file-utils
MOD_FLUID_CMAKE_BOOL=		WITH_MOD_FLUID
MOD_FLUID_IMPLIES=		TBB
MOD_OCEANSIM_CMAKE_BOOL=	WITH_MOD_OCEANSIM
MOD_OCEANSIM_IMPLIES=		FFTW3
MOD_REMESH_CMAKE_BOOL=		WITH_MOD_REMESH
NLS_CMAKE_BOOL=			WITH_INTERNATIONAL
NLS_USES=			gettext-tools
OPENAL_CMAKE_BOOL=		WITH_OPENAL
OPENAL_USES=			openal:al,alut
OPENCOLORIO_CMAKE_BOOL=		WITH_OPENCOLORIO
OPENCOLORIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio \
				libyaml-cpp.so:devel/yaml-cpp \
				libexpat.so:textproc/expat2 \
				libpystring.so:devel/pystring
OPENCOLORIO_USES=		minizip
OPENEXR_CFLAGS=			-I${LOCALBASE}/include/Imath
OPENEXR_CMAKE_BOOL=		WITH_IMAGE_OPENEXR
OPENEXR_LIB_DEPENDS=		libImath.so:math/Imath \
				libOpenEXR.so:graphics/openexr
OPENIMAGEDN_CMAKE_BOOL=		WITH_OPENIMAGEDENOISE
OPENIMAGEDN_IMPLIES=		TBB
OPENIMAGEDN_LIB_DEPENDS=	libOpenImageDenoise.so:graphics/oidn
OPENJPEG_CMAKE_BOOL=		WITH_IMAGE_OPENJPEG
OPENJPEG_LIB_DEPENDS=		libopenjp2.so:graphics/openjpeg
OPENPGL_CMAKE_BOOL=		WITH_CYCLES_PATH_GUIDING
OPENPGL_LIB_DEPENDS=		libopenpgl.so:graphics/openpgl
OPENSUBDIV_CMAKE_BOOL=		WITH_OPENSUBDIV
OPENSUBDIV_LIB_DEPENDS=		libosdCPU.so:graphics/opensubdiv
OPENVDB_CMAKE_BOOL=		WITH_OPENVDB WITH_OPENVDB_BLOSC
OPENVDB_IMPLIES=		OPENEXR TBB
OPENVDB_LIB_DEPENDS=		libopenvdb.so:misc/openvdb
OPENXR_CMAKE_BOOL=		WITH_XR_OPENXR
OPENXR_LIB_DEPENDS=		libopenxr_loader.so:graphics/openxr
PIPEWIRE_CMAKE_BOOL=		WITH_PIPEWIRE
PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
POTRACE_CMAKE_BOOL=		WITH_POTRACE
POTRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
PUGIXML_CMAKE_BOOL=		WITH_PUGIXML WITH_IO_GREASE_PENCIL
# GP IO needs pugixml - turn it off with pugi
PUGIXML_LDFLAGS=		-lfmt
PUGIXML_LIB_DEPENDS=		libpugixml.so:textproc/pugixml \
				libfmt.so:devel/libfmt
# libfmt is in place via openimageio, add here as we need -lfmt in LDFLAGS
PULSEAUDIO_CMAKE_BOOL=		WITH_PULSEAUDIO WITH_PULSEAUDIO_DYNLOAD
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
QUADRIFLOW_CMAKE_BOOL=		WITH_QUADRIFLOW
RUBBERBAND_CMAKE_BOOL=		WITH_RUBBERBAND
RUBBERBAND_LIB_DEPENDS=		librubberband.so:audio/rubberband
SDL_CMAKE_BOOL=			WITH_SDL
SDL_USE=			SDL=sdl2
SDL_USES=			sdl
SIMD_CMAKE_BOOL=		WITH_CPU_SIMD
SIMD_EXTRA_PATCHES_OFF=		${PATCHDIR}/extra-patch-simd-off
SNDFILE_CMAKE_BOOL=		WITH_CODEC_SNDFILE
SNDFILE_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
TBB_CMAKE_BOOL=			WITH_TBB
TBB_LIB_DEPENDS=		libtbb.so:devel/onetbb
THUMBNAILER_CMAKE_BOOL=		WITH_BLENDER_THUMBNAILER
TRACE_CMAKE_BOOL=		WITH_POTRACE
TRACE_LIB_DEPENDS=		libpotrace.so:graphics/libpotrace
USD_BROKEN=			does not build with current USD port
USD_CMAKE_BOOL=			WITH_USD
USD_IMPLIES=			TBB
USD_LIB_DEPENDS=		libusd_ms.so:graphics/openusd
VULKAN_BUILD_DEPENDS=		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_CMAKE_BOOL=		WITH_VULKAN_BACKEND
VULKAN_LDFLAGS=			-lshaderc_shared -lSPIRV-Tools-shared
VULKAN_LIB_DEPENDS=		libshaderc_shared.so:graphics/shaderc \
				libSPIRV-Tools-shared.so:graphics/spirv-tools \
				libvulkan.so:graphics/vulkan-loader
VULKAN_USES=			localbase:ldflags # only relevant in the case of most options off
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.15:graphics/wayland-protocols \
				wayland>=1.12:graphics/wayland \
				libdecor>0:x11-toolkits/libdecor
WAYLAND_CATEGORIES=		wayland
WAYLAND_CMAKE_BOOL=		WITH_GHOST_WAYLAND WITH_GHOST_WAYLAND_LIBDECOR \
				WITH_GHOST_WAYLAND_DYNLOAD
WAYLAND_LIB_DEPENDS=		libxkbcommon.so:x11/libxkbcommon
WEBP_CMAKE_BOOL=		WITH_IMAGE_WEBP
WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
XINPUT_CMAKE_BOOL=		WITH_X11_XINPUT
XINPUT_USE=			XORG=xi

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
	@${RM} ${STAGEDIR}/${DATADIR}/${DISTVERSION:R}/scripts/addons_core/io_scene_gltf2/libextern_draco.so

post-install-MENU-on:
	@-update-desktop-database -q

.include <bsd.port.mk>
