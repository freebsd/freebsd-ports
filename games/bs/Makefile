# New ports collection makefile for:	bs
# Version required:			2.1
# Date created:				11 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		bs-2.1
CATEGORIES=		games
MASTER_SITES=		ftp://locke.ccil.org/pub/esr/

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=
MAN6=			bs.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bs ${PREFIX}/bin/bs
	@ ${INSTALL_MAN} ${WRKSRC}/bs.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
