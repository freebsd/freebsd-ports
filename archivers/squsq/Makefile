# New ports collection makefile for:	squsq
# Date created:				09 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	squsq
PORTVERSION=	3.3
CATEGORIES=	archivers
MASTER_SITES=	NETBSD http://freebsd.nsu.ru/distfiles/
DISTNAME=	t20-squsq-3.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressor/decompressor for CP/M "Squeeze" compressed files

CONFLICTS=	squirrel-[0-9]*
WRKSRC=		${WRKDIR}/t20-squsq
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/sq bin/usq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include <bsd.port.mk>
