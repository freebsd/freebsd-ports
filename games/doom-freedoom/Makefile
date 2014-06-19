# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	freedoom
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-iwad
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-iwad-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Complete Doom-based game IWAD that is Free Software

USES=		zip
NO_BUILD=	yes

DATADIR=	${DMDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	%%DATADIR%%/doom2.wad
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	ChangeLog NEWS README

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doom2.wad ${STAGEDIR}${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
