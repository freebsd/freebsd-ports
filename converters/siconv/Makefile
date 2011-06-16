# ex:ts=8
# New ports collection makefile for:	siconv
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	siconv
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.technocage.com/~caskey/siconv/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert data from one character set to another

DEPRECATED=	Looks like an abandonware, no more public distfiles
EXPIRATION_DATE=	2011-08-01

USE_ICONV=	yes
PLIST_FILES=	bin/siconv

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -o ${WRKSRC}/siconv ${WRKSRC}/siconv.c -liconv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/siconv ${PREFIX}/bin

.include <bsd.port.mk>
