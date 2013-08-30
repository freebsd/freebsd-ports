# Created by: Mathias Monnerville <mathias@monnerville.com>
# $FreeBSD$

PORTNAME=	sextractor
PORTVERSION=	2.5.0
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.iap.fr/pub/from_users/bertin/sextractor/ \
		http://download.gna.org/kanicule/freebsd/distfiles/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Catalogue of objects builder from astronomical images

GNU_CONFIGURE=	yes
USES=		gmake

MAN1=	sex.1
MANX=	sex.x

OPTIONS_DEFINE=	STATIC
OPTIONS_DEFAULT=	STATIC

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--enable-static
.endif

.include <bsd.port.post.mk>
