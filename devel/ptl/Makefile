PORTNAME=		ptl
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.3
PORTREVISION=		4
CATEGORIES=		devel

MAINTAINER=	erik@tenku.dk
COMMENT=	Lightweight C++11 multithreading tasking system
WWW=		https://github.com/jrmadsen/PTL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jrmadsen
GH_PROJECT=	PTL

CMAKE_OFF=	BUILD_STATIC_LIBS

PLIST_SUB+=	SHLIB_SHVER="${DISTVERSION:R:R}" \
		SHLIB_VER="${DISTVERSION}"

.include <bsd.port.mk>
