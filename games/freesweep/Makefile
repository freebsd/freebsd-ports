# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	freesweep
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Minesweeper-style game for text-mode terminals

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	rwestlund

USES=		gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${DATADIR} \
		--with-scoresdir=${DATADIR} \
		--disable-debug-log
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README.md
PLIST_FILES=	"@(,games,2555) bin/${PORTNAME}" man/man6/${PORTNAME}.6.gz \
		%%DATADIR%%/sweeprc "@(,games,0664) %%DATADIR%%/sweeptimes"
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freesweep ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TOUCH} ${STAGEDIR}${DATADIR}/sweeptimes
	${INSTALL_DATA} ${WRKSRC}/sweeprc ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/freesweep.6 ${STAGEDIR}${PREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
