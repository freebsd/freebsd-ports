# New ports collection makefile for:	hffzip
# Date created:				10 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	hffzip
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://utenti.quipo.it/claudioscordino/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File compressor based on Huffman coding

PLIST_FILES=	bin/hffzip
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		 ${PREFIX}/bin

.include <bsd.port.mk>
