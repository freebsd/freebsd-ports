PORTNAME=	libosmpbf
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for handling binary OpenStreetMap data
WWW=		https://github.com/scrosby/OSM-binary

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	scrosby
GH_PROJECT=	OSM-binary

USES=		cmake compiler:c++17-lang
USE_CXXSTD=	c++17

.include <bsd.port.mk>
