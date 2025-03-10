PORTNAME=	gnushogi
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	GNU version of Shogi
WWW=		https://www.gnu.org/software/gnushogi/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo

GNU_CONFIGURE=	yes

INFO=		gnushogi
PLIST_FILES=	${DATADIR}/gnushogi.bbk bin/gnushogi \
		share/man/man6/gnushogi.6.gz
PORTDOCS=	BOOKFILES PORTING shogi.rules tutorial1.gam tutorial2.gam

OPTIONS_DEFINE=	DOCS

pre-build:
	cd ${WRKSRC}/doc && makeinfo --no-split gnushogi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnushogi/gnushogi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/gnushogi.6 \
		${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_DATA} ${WRKSRC}/doc/gnushogi.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gnushogi/gnushogi.bbk ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
