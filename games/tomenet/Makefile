# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomenet
PORTVERSION=	4.5.4
CATEGORIES=	games
MASTER_SITES=	http://tomenet.net/downloads/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Online multiplayer rogue-like role-playing game

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	${WRKSRC}/makefile

USES=		ncurses
USE_GMAKE=	yes
CFLAGS+=	-DDEFAULT_PATH="\\\"${DATADIR}/lib/\\\""

SUB_FILES=	pkg-message

do-install:
.for f in tomenet tomenet.server accedit evilmeta
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	(cd ${WRKDIR}/${DISTNAME} && ${COPYTREE_SHARE} lib ${DATADIR})
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/.tomenetrc ${ETCDIR}/tomenetrc

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TomeNET-Guide.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
