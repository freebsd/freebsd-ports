PORTNAME=	venice
DISTVERSION=	0.753beta
CATEGORIES=	finance java
MASTER_SITES=	SF/mov/${PORTNAME}/0.753%20beta/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Merchant Of Venice, a stock market trading program
WWW=		https://mov.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gnome java

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DESKTOP_ENTRIES="Venice" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Office;Finance;" false
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

PORTDOCS=	changelog.txt doc/manual.html doc/manual.txt readme.txt

OPTIONS_DEFINE=	DOCS

ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}

.for s in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
