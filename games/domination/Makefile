# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	domination
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/d/D/}/${PORTVERSION}/:game \
		http://domination.sourceforge.net/maps/
DISTFILES=	${PORTNAME:S/d/D/}_${DISTVERSION}${EXTRACT_SUFX}:game \
		${MAPS:S/$/.zip/}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/d/D/}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Board game that is a bit like the well known game Risk

LICENSE=	GPLv3

USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.txt *.ini *.htm *.cards *.map
USE_JAVA=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S/d/D/}

# Please contact the MAINTAINER if a Map is missing
MAPS=		solar bigeurope google europass europe artic sudamerica \
		MiddleEast-Qatar kosova Falkland-Islands england sw_baltic \
		spain swiss france austria austria-hungary eire haiti brasil \
		benelux canada germany northeurope germany1871 \
		Deutsches_Reich_1871 eesti estonia mexico serbia fletzmap \
		greece North_of_Italy bayern berlin navarra Illes_Balears \
		calw wuppertal kerzell ennepe-ruhr-kreis cologne saarland \
		andorra catalunya astadt dortmund rio_de_janeiro caribbean \
		Nuremberg_Public_Transit discworld aztec GTA_SAN_AN \
		middleearth LOTR2 wow randland Riskopoly SuperRiskopoly \
		trivia chutes sudoku conquest chrono_trigger startrek usa8 \
		civilwar usa hawaii ohio nyc zertina fortress estlandr \
		periodictable sylsia troisdorf wolken castle naerr cow \
		westfalenhalle union rub gymnasium simpsons_world simpsons \
		germany2

PORTDOCS=	ChangeLog.txt ReadMe.txt commands.txt
OPTIONS_DEFINE=	DOCS

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}-FlashGUI ${PORTNAME}-Increment1GUI \
		${PORTNAME}-SimpleGUI ${PORTNAME}-SwingGUI \
		pkg-deinstall

DESKTOP_ENTRIES="Domination" "" "${PORTNAME}" \
		"${PORTNAME}-SwingGUI" "Game;StrategyGame;" ""

.include <bsd.port.options.mk>

post-extract-script:
.for f in ${MAPS:S/$/.zip/}
	@${UNZIP_CMD} -qo -d ${WRKSRC}/maps ${_DISTDIR}/${f}
.endfor

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"help lib maps resources saves *.jar *.htm *.txt *.ini" \
			${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-* ${STAGEDIR}${PREFIX}/bin/
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} *.sh ${STAGEDIR}${DATADIR})
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 774 saves)
	${LN} -sf ${DATADIR}/resources/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
