# New ports collection makefile for:	eights
# Date created:				21 Febuary 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	eights
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://dxkelly.freeshell.org/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text based card game, the objective is to get rid of all your cards

PLIST_FILES=	bin/eights
WRKSRC=		${WRKDIR}

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
