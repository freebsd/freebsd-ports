PORTNAME=	filament
DISTVERSIONPREFIX=	v
DISTVERSION=	1.62.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time physically based rendering engine
WWW=		https://google.github.io/filament/ \
		https://github.com/google/filament

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation breaks: unexpected token in operand, see https://github.com/google/filament/issues/6131
BROKEN_i386=	compilation breaks: register r11 is only available in 64-bit mode
BROKEN_powerpc=		compilation breaks: invalid register name, see https://github.com/google/filament/issues/7552
BROKEN_powerpc64=	compilation breaks: invalid register name, see https://github.com/google/filament/issues/7552
BROKEN_powerpc64le=	compilation breaks: invalid register name, see https://github.com/google/filament/issues/7552

BUILD_DEPENDS=	bash:shells/bash \
		evdev-proto>0:devel/evdev-proto

USES=		cmake compiler:c++17-lang localbase:ldflags python:build sdl shebangfix xorg
USE_SDL=	sdl2
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	google

SHEBANG_FILES=	build/launch-c.in build/launch-cxx.in

#CMAKE_ON=	BUILD_SHARED_LIBS # not yet supported, see https://github.com/google/filament/issues/1075
CMAKE_OFF=	USE_STATIC_LIBCXX FILAMENT_ENABLE_JAVA
CMAKE_ARGS+=	-DDIST_DIR="." # prevent subdirectory for libraries
CMAKE_ARGS+=	-DUSE_CCACHE:BOOL=${CCACHE_ENABLED:tu}
CMAKE_ARGS+=	-DPython3_EXECUTABLE=${PYTHON_CMD}

LDFLAGS+=	-lexecinfo -lSDL2

OPTIONS_DEFINE=		SAMPLES
OPTIONS_SUB=		yes

SAMPLES_DESC=		Build samples
SAMPLES_CMAKE_OFF=	-DFILAMENT_SKIP_SAMPLES=ON

# gltf_viewer is broken with the Vulkan backend, see https://github.com/google/filament/issues/6445

post-patch:
	@${REINPLACE_CMD} -e 's|"/proc/self/exe"|"/proc/curproc/file"|' ${WRKSRC}/libs/utils/src/linux/Path.cpp

post-install:
	# remove unnecessary files
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r README.md LICENSE docs
	# remove conflicting file, see https://github.com/google/filament/issues/5957
	@${RM} ${STAGEDIR}${PREFIX}/lib/libzstd.a
	# remove files installed by the improperly bundled spirv-tools package, see https://github.com/google/filament/issues/8965
	@${FIND} ${STAGEDIR}${PREFIX} -iname "*spirv*" -delete
	@${RM} -r ${STAGEDIR}${PREFIX}/include/spirv-tools # workaround for the find(1) -delete bug, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=288277
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.mk>
