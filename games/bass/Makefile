# New ports collection makefile for: bass (Beneath a Steel Sky)
# Date created:        Tue Sep  2 23:34:32 BST 2003
# Whom:                Alex Trull <alexander@trull.com>
#
# $FreeBSD$
#

PORTNAME=	bass
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm
DISTNAME=	BASS-CD

MAINTAINER=	alexander@trull.com
COMMENT=	Beneath a Steel Sky: a post-apocalyptic futuristic graphical adventure

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/sky-cd
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dsk ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in readme.txt
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e "s:%%DATADIR%%:${DATADIR}:g" pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
