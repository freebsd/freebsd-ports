# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imlib2
PORTVERSION=	0.1.00
PORTREVISION=	7
CATEGORIES=	graphics

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PECL extension if imlib2

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP202

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

# libImlib2 may or may not depend on X, however,
# imlib2 extension doesn't need X related functions in libImlib2
CFLAGS+=	-DX_DISPLAY_MISSING -Wno-deprecated

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/config.m4
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,' ${WRKSRC}/imlib2.c

.include <bsd.port.mk>
