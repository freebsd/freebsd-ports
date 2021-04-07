PORTNAME=	termcolor
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ library for printing colored messages to the terminal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ikalnytskyi

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/termcolor/termcolor.hpp \
		lib/cmake/termcolor/termcolor-config.cmake \
		lib/cmake/termcolor/termcolor-targets.cmake

.include <bsd.port.mk>
