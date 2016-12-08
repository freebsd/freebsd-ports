# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	busybee
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://hyperdex.org/src/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High-performance messaging layer

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libe.so:devel/libe
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpo6.pc:devel/libpo6

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig

ONLY_FOR_ARCHS=	amd64

.include <bsd.port.mk>
