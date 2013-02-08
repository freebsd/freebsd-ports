# $FreeBSD$

PORTNAME=	domination
PORTVERSION=	1.1.1.2
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/d/D/}/${PORTVERSION}/:game  \
		http://domination.sourceforge.net/maps/
DISTFILES=	${PORTNAME:S/d/D/}_${DISTVERSION}${EXTRACT_SUFX}:game \
		${MAPS:S/$/.zip/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Board game that is a bit like the well known game Risk

LICENSE=	GPLv3

FETCH_ARGS?=	-Fpr
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S/d/D/}

# Please contact the MAINTAINER if a Map is missing
MAPS=		solar bigeurope google europass europe artic sudamerica \
		MiddleEast-Qatar kosova Falkland-Islands england sw_baltic \
		spain swiss france austria austria-hungary eire haiti brasil \
		benelux canada germany northeurope germany1871 eesti estonia \
		mexico serbia fletzmap greece North_of_Italy bayern berlin \
		navarra Illes_Balears calw wuppertal kerzell ennepe-ruhr-kreis \
		cologne saarland andorra catalunya astadt dortmund rio_de_janeiro \
		caribbean Nuremberg_Public_Transit discworld aztec GTA_SAN_AN \
		middleearth LOTR2 wow randland Riskopoly SuperRiskopoly trivia \
		chutes sudoku conquest chrono_trigger startrek usa8 civilwar \
		usa hawaii ohio nyc zertina fortress estlandr periodictable \
		sylsia troisdorf wolken castle naerr cow westfalenhalle \
		union rub gymnasium simpsons_world simpsons germany2

PLIST_FILES=	bin/${PORTNAME}-FlashGUI \
		bin/${PORTNAME}-Increment1GUI \
		bin/${PORTNAME}-SimpleGUI \
		bin/${PORTNAME}-SwingGUI \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	ChangeLog.txt ReadMe.txt commands.txt todo.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}-FlashGUI \
		${PORTNAME}-Increment1GUI \
		${PORTNAME}-SimpleGUI \
		${PORTNAME}-SwingGUI

DESKTOP_ENTRIES="Domination" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}-SwingGUI" "Game;StrategyGame;" "false"

.include <bsd.port.options.mk>

post-extract-script:
.for f in ${MAPS:S/$/.zip/}
	@${UNZIP_CMD} -qo -d ${WRKSRC}/maps ${DISTDIR}/${DIST_SUBDIR}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-* ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "help lib maps resources saves *.jar *.cmd *.htm *.txt *.ini" ${DATADIR})
	@(cd ${WRKSRC} && ${INSTALL_SCRIPT} *.sh ${DATADIR})
	@(cd ${DATADIR} && ${CHMOD} 774 saves)

	${LN} -sf ${DATADIR}/resources/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
