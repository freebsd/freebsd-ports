# ex:ts=8
# New ports collection makefile for:	siconv
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	siconv
PORTVERSION=	0.2
CATEGORIES=	converters
MASTER_SITES=	http://www.technocage.com/~caskey/siconv/download/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -o ${WRKSRC}/siconv ${WRKSRC}/siconv.c -lgiconv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/siconv ${PREFIX}/bin

.include <bsd.port.mk>
