# New ports collection makefile for:	blue
# Version required:			2.3
# Date created:				6 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		blue-2.3
CATEGORIES=		games
MASTER_SITES=		ftp://locke.ccil.org/pub/esr/

MAINTAINER=		andy@icc.surw.chel.su

NO_WRKSUBDIR=	yes
ALL_TARGET=
MAN6=			blue.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/blue ${PREFIX}/bin/blue
	@ ${INSTALL_MAN} ${WRKSRC}/blue.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
