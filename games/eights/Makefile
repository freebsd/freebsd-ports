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

MAINTAINER=	bob@fly.homeunix.org

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
