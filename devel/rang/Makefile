PORTNAME=	rang
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal header-only modern C++ library for terminal goodies
WWW=		https://agauniyal.github.io/rang/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	agauniyal

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/rang.hpp \
		lib/cmake/rang/rang-config-version.cmake \
		lib/cmake/rang/rang-config.cmake \
		libdata/pkgconfig/rang.pc

.include <bsd.port.mk>
