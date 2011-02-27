# New ports collection makefile for:	doom-hr2
# Date created:				21 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	hr2
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.doomworld.com/hr2/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	hr2final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hell Revealed II is a megawad, a 32-level replacement for DooM II

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}/${PORTNAME}

PLIST_FILES=	%%DATADIR%%/hr2final.wad
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	hr2final.txt

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/hr2final.wad ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/hr2final.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
