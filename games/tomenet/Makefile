PORTNAME=	tomenet
PORTVERSION=	4.6.0
CATEGORIES=	games
MASTER_SITES=	http://tomenet.eu/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online multiplayer rogue-like role-playing game
WWW=		https://tomenet.eu/

USES=		gmake ncurses tar:bzip2

MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DDEFAULT_PATH="\\\"${DATADIR}/lib/\\\""

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS_DEFINE=	DOCS

do-install:
.for f in tomenet tomenet.server accedit
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/${DISTNAME} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/.tomenetrc ${STAGEDIR}${ETCDIR}/tomenetrc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TomeNET-Guide.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
