# New ports collection makefile for: fotaq (Flight of the Amazon Queen)
# Date created:        Fri Mar 26 23:34:32 BST 2004
# Whom:                Alex Trull <freebsd.alex@trull.org>
#
# $FreeBSD$
#

PORTNAME=	fotaq
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Flight%20of%20the%20Amazon%20Queen
DISTNAME=	FOTAQ_Talkie

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Flight of the Amazon Queen: a classic graphical adventure

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/queen.1c ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${SED} -e "s:%%DATADIR%%:${DATADIR}:g" ${.CURDIR}/pkg-message \
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
