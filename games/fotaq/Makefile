# New ports collection makefile for: fotaq (Flight of the Amazon Queen)
# Date created:        Fri Mar 26 23:34:32 BST 2004
# Whom:                Alex Trull <alexander@trull.com>
#
# $FreeBSD$
#

PORTNAME=	fotaq
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm
DISTNAME=	FOTAQ_Talkie

MAINTAINER=	alexander@trull.com
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
