PORTNAME=	pangzero
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Super Pang
WWW=		http://apocalypse.rulez.org/pangzero

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-SDL>=0:devel/p5-SDL

USES=		perl5

DESKTOP_ENTRIES="Pang Zero" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" ""
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile*" -delete
.for f in *.png *.jpg
	@${CP} -a ${WRKDIR}/${f} ${WRKSRC}/data
.endfor

do-install:
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bin data" ${STAGEDIR}${DATADIR})

	${LN} -sf ${DATADIR}/data/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
