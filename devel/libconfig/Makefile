PORTNAME=	libconfig
DISTVERSION=	1.8.3
CATEGORIES=	devel
MASTER_SITES=	https://hyperrealm.github.io/${PORTNAME}/dist/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Simple library for processing structured configuration files
WWW=		https://hyperrealm.github.io/libconfig/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake:testing pathfix
USE_LDCONFIG=	yes

CONFLICTS=	wand-libconfig

CMAKE_TESTING_ON=	BUILD_TESTS

CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_TESTS

.include <bsd.port.mk>
