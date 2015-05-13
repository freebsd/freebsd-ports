# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomenet
PORTVERSION=	4.6.0
CATEGORIES=	games
MASTER_SITES=	http://tomenet.eu/downloads/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Online multiplayer rogue-like role-playing game

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile

USES=		execinfo gmake ncurses tar:bzip2
CFLAGS+=	-DDEFAULT_PATH="\\\"${DATADIR}/lib/\\\"" \
		${EXECINFO_CPPFLAGS}
LDFLAGS+=	${EXECINFO_LDFLAGS}
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

do-install:
.for f in tomenet tomenet.server accedit
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/${DISTNAME} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/.tomenetrc ${STAGEDIR}${ETCDIR}/tomenetrc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TomeNET-Guide.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
