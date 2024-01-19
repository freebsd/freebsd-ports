PORTNAME=	loguru
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0-49
DISTVERSIONSUFFIX=	-g4adaa18
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and flexible C++ logging library
WWW=		https://github.com/emilk/loguru

LICENSE=	PD

USES=		compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	emilk

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/loguru.cpp \
		include/loguru.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.hpp ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cpp ${STAGEDIR}${PREFIX}/include # #include <loguru.cpp> is recommended by the upstream

.include <bsd.port.mk>
