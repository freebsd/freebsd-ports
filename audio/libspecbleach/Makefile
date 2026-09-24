PORTNAME=	libspecbleach
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for audio noise reduction
WWW=		https://github.com/lucianodato/libspecbleach

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato

CMAKE_ON=	SPECBLEACH_BUILD_EXTRAS

PLIST_FILES=	include/specbleach.hpp \
		include/specbleach_denoiser.h \
		include/specbleach_export.h \
		include/specbleach_stereo.h \
		include/specbleach_stereo.hpp \
		include/specbleach_version.h \
		lib/libspecbleach.so \
		lib/libspecbleach.so.0 \
		lib/libspecbleach.so.0.4.1 \
		lib/libspecbleach_extras.so \
		lib/libspecbleach_extras.so.0 \
		lib/libspecbleach_extras.so.0.4.1 \
		libdata/pkgconfig/specbleach.pc \
		libdata/pkgconfig/specbleach-extras.pc \
		lib/cmake/libspecbleach/libspecbleachConfig.cmake \
		lib/cmake/libspecbleach/libspecbleachConfigVersion.cmake \
		lib/cmake/libspecbleach/libspecbleachExtrasTargets-release.cmake \
		lib/cmake/libspecbleach/libspecbleachExtrasTargets.cmake \
		lib/cmake/libspecbleach/libspecbleachTargets-release.cmake \
		lib/cmake/libspecbleach/libspecbleachTargets.cmake

.include <bsd.port.mk>
