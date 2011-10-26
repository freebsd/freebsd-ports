# New ports collection makefile for:	cconv
# Date created:		2011-04-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cconv
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	chinese converters
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified-Traditional Chinese conversion tool

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|unicode.h||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|UTF-TW|UTF8-TW|g' ${WRKSRC}/main.c

.include <bsd.port.mk>
