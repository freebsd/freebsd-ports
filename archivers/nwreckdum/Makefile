# New ports collection makefile for:	nwreckdum
# Date created:				27 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	nwreckdum
PORTVERSION=	0.0.6
CATEGORIES=	archivers games
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Utility for extracting/creating Quake PAK files

PLIST_FILES=	bin/nwreckdum

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
