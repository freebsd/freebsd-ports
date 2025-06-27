PORTNAME=	flycast
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-platform Sega Dreamcast emulator
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio>0:net/asio
LIB_DEPENDS=	libchdr.so:devel/libchdr \
		libcurl.so:ftp/curl \
		libminiupnpc.so:net/miniupnpc \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++20-lang pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
USE_SDL=	sdl2

.include "${.CURDIR}/Makefile.tuples"

CMAKE_ON=	USE_HOST_LIBCHDR

OPTIONS_DEFINE=		DOCS LUA OPENMP VULKAN
OPTIONS_DEFAULT=	ALSA AO LUA OPENMP OSS VULKAN
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA AO OSS PULSEAUDIO

# building with lua support fails on i386, see also
# https://github.com/vinniefalco/LuaBridge/issues/302
OPTIONS_EXCLUDE_i386=	LUA

VULKAN_DESC=	Build with Vulkan support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_BOOL=		USE_LIBAO

LUA_USES=		lua:52+
LUA_CMAKE_BOOL=		USE_LUA

OPENMP_CMAKE_BOOL=	USE_OPENMP

OSS_CMAKE_BOOL=		USE_OSS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO

VULKAN_BUILD_DEPENDS=	glslang>0:graphics/glslang \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_CMAKE_BOOL=	USE_HOST_GLSLANG \
			USE_VULKAN

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

# For maintainer (do not forget to clean up Makefile.tuples afterwards to
# remove useless submodules)
Makefile.tuples::
	${RM} -f ${.CURDIR}/Makefile.tuples
	${RM} -rf ${WRKDIR}/.maintainer.checkout
	${MKDIR} ${WRKDIR}/.maintainer.checkout
	(cd ${WRKDIR}/.maintainer.checkout && \
		git clone --recursive --branch=${DISTVERSIONPREFIX}${DISTVERSION} \
		https://github.com/${GH_ACCOUNT}/${PORTNAME} . && \
		${SH} ${FILESDIR}/gen_gh_tuple.sh > ${.CURDIR}/Makefile.tuples)

.include <bsd.port.mk>
