# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=		libe
PORTVERSION=		0.11.0
DISTVERSIONPREFIX=	releases/
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	High-performance datastructures and utilities for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpo6.pc:devel/libpo6

GNU_CONFIGURE=	yes

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	rescrv
GH_PROJECT=	e

.include <bsd.port.mk>
