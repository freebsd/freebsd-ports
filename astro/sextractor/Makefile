# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	sextractor
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.iap.fr/pub/from_users/bertin/sextractor/ \
		http://download.gna.org/kanicule/freebsd/distfiles/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Catalogue of objects builder from astronomical images

GNU_CONFIGURE=	yes
USES=		gmake

OPTIONS_DEFINE=	STATIC
OPTIONS_DEFAULT=	STATIC

STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.mk>
