# New ports collection makefile for:	visprint
# Date created:		11 November 2006
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	visprint
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.tastyrabbit.net/visprint/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates fractal fingerprint images based on any data

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpng

MANCOMPRESSED=	yes

PLIST_FILES=	bin/visprint

MAN1=		visprint.1

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c visprint.c)
	(cd ${WRKSRC} && ${CC} ${LDFLAGS} visprint.o -o visprint)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visprint ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/visprint.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
