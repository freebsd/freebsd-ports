# New ports collection makefile for:	hffzip
# Date created:				10 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	hffzip
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://retis.sssup.it/~scordino/projects/ \
		http://ngsoftwareltd.com/freebsd/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File compressor based on Huffman coding

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/hffzip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
