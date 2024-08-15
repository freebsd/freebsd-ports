PORTNAME=	libosmpbf
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for handling binary OpenStreetMap data
WWW=		https://github.com/openstreetmap/OSM-binary

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap
GH_PROJECT=	OSM-binary

.include <bsd.port.mk>
