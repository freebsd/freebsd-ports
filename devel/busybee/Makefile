# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	busybee
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://hyperdex.org/src/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High-performance messaging layer

LICENSE=	BSD

LIB_DEPENDS=	e:${PORTSDIR}/devel/libe
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpo6.pc:${PORTSDIR}/devel/libpo6

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

ONLY_FOR_ARCHS=	amd64

.include <bsd.port.mk>
