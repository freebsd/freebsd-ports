# New ports collection makefile for:	galaxis
# Version required:			1.1
# Date created:				30 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	galaxis-1.1
CATEGORIES=	games
MASTER_SITES=	ftp://locke.ccil.org/pub/esr/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	# empty
MAN6=		galaxis.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/galaxis ${PREFIX}/bin/galaxis
	${INSTALL_MAN} ${WRKSRC}/galaxis.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
