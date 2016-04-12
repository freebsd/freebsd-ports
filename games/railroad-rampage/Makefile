# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	railroad-rampage
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
DISTNAME=	RailroadRampage_${PORTVERSION}_Linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tower Defence-like Arcade and Strategy combination

BUILD_DEPENDS=	bgdc:devel/bennugd-core \
		${LOCALBASE}/lib/bennugd/libmod_grproc.so:devel/bennugd-modules
RUN_DEPENDS=	bgdi:devel/bennugd-core \
		${LOCALBASE}/lib/bennugd/libmod_grproc.so:devel/bennugd-modules

USES=		zip

WRKSRC=		${WRKDIR}/RailroadRampage_Linux
SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/railroad-rampage
PORTDOCS=	ReadMe.txt
PORTDATA=	*

DESKTOP_ENTRIES="Railroad Rampage" \
		"Tower Defence-like Arcade and Strategy combination" \
		"${DATADIR}/RailroadRampage.png" \
		"railroad-rampage" \
		"Game;StrategyGame;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${SETENV} \
		LD_LIBRARY_PATH="${LOCALBASE}/lib/bennugd" \
		BENNUDIR="${LOCALBASE}/lib/bennugd" \
		"${LOCALBASE}/bin/bgdc" RailroadRampage.prg || true; \
		[ -e RailroadRampage.dcb ]

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Music Sound" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/traintd.fpg ${WRKSRC}/RailroadRampage.dcb \
		${WRKSRC}/RailroadRampage.png ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
