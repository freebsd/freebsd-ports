# New ports collection makefile for:	xchain
# Date created:				13 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xchain
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://linux.tucows.com/files/x11/entertain/
DISTNAME=	${PORTNAME}_1.0-2

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0

USE_X_PREFIX=	yes
MAN6=		xchain.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xchain.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/doc/xchain
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchain
	${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/doc/xchain

.include <bsd.port.mk>
