PORTNAME=	gsl-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.42.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the C++ Core Guidelines Support Library
WWW=		https://github.com/gsl-lite/gsl-lite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes

PLIST_FILES=	include/gsl-lite/gsl-lite.hpp \
		include/gsl/gsl-lite.hpp \
		lib/cmake/gsl-lite/gsl-lite-config-version.cmake \
		lib/cmake/gsl-lite/gsl-lite-config.cmake \
		lib/cmake/gsl-lite/gsl-lite-targets.cmake

NO_ARCH=	yes

.include <bsd.port.mk>
