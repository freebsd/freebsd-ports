# New ports collection makefile for:	blue
# Version required:			2.4
# Date created:				6 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		blue-2.4
CATEGORIES=		games
MASTER_SITES=		ftp://locke.ccil.org/pub/esr/

MAINTAINER=		ports@FreeBSD.org

ALL_TARGET=
MAN6=			blue.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/blue ${PREFIX}/bin/blue
	@ ${INSTALL_MAN} ${WRKSRC}/blue.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
