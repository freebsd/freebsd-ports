# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=		busybee
PORTVERSION=		0.7.0
DISTVERSIONPREFIX=	releases/
CATEGORIES=		devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	High-performance messaging layer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libe.so:devel/libe \
		libpo6.so:devel/libpo6

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	rescrv

.include <bsd.port.mk>
