# $FreeBSD$

PORTNAME=	rrd
DISTVERSION=	1.1.3
PORTREVISION=	4
CATEGORIES=	databases pear

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP bindings to rrd tool system

LICENSE=	PHP301

LIB_DEPENDS=	librrd.so:databases/rrdtool

LDFLAGS+=	-L${LOCALBASE}/lib

USES=		php:pecl
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
