# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosmpbf
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
PORTREVISION=	15
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for handling binary OpenStreetMap data

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.osmpbf

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	scrosby
GH_PROJECT=	OSM-binary

USES=		cmake compiler:c++11-lang
USE_CXXSTD=	c++11

.include <bsd.port.mk>
