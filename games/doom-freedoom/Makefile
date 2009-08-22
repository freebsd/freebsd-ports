# New ports collection makefile for:	doom-freedoom
# Date created:				23 November 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	freedoom
PORTVERSION=	0.6.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-iwad-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Complete Doom-based game IWAD that is Free Software

USE_ZIP=	yes
NO_BUILD=	yes

DATADIR=	${DMDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	%%DATADIR%%/doom2.wad
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	ChangeLog NEWS README

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doom2.wad ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
