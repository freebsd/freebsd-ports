# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomenet
PORTVERSION=	4.5.5
CATEGORIES=	games
MASTER_SITES=	http://tomenet.net/downloads/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Online multiplayer rogue-like role-playing game

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile

USES=		gmake ncurses
CFLAGS+=	-DDEFAULT_PATH="\\\"${DATADIR}/lib/\\\""
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

do-install:
.for f in tomenet tomenet.server accedit evilmeta
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/${DISTNAME} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/.tomenetrc ${STAGEDIR}${ETCDIR}/tomenetrc

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TomeNET-Guide.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
