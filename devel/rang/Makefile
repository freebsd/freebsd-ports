PORTNAME=	rang
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal header-only modern C++ library for terminal goodies
WWW=		https://agauniyal.github.io/rang/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	agauniyal

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/rang.hpp \
		lib/cmake/rang/rang-config-version.cmake \
		lib/cmake/rang/rang-config.cmake \
		lib/cmake/rang/rang-targets.cmake \
		libdata/pkgconfig/rang.pc

# tests as of 3.3: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
