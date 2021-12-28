PORTNAME=	yder
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.14
CATEGORIES=	devel

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Logging library for C applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

LIB_DEPENDS+=	libjansson.so:devel/jansson
LIB_DEPENDS+=	liborcania.so:devel/orcania

BUILD_DEPENDS+=	orcania>0:devel/orcania

RUN_DEPENDS+=	jansson>0:devel/jansson

CMAKE_ARGS=	-DWITH_JOURNALD=off

.include <bsd.port.mk>
