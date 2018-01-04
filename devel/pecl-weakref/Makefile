# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	weakref
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	devel pear
DISTNAME=	Weakref-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PECL Weakref extension

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limitw:^0\.2\.[0-9]*

USES=		php:pecl
IGNORE_WITH_PHP=	70 71 72

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
