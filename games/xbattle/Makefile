# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	xbattle
PORTVERSION=	5.4.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	GENTOO/distfiles \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Concurrent multi-player battle strategy game

LICENSE=	XBATTLE_LICENSE
LICENSE_NAME=	XBATTLE License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xdialog>0:${PORTSDIR}/x11/xdialog

USES=		imake
USE_XORG=	x11 xext
USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

SUB_FILES=	${PORTNAME}-menu

DESKTOP_ENTRIES="XBattle" "" "${PORTNAME}" \
		"${PORTNAME}-menu" "Game;ArcadeGame;" ""

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-menu ${STAGEDIR}${PREFIX}/bin/
.for d in xbas xbos xbts
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}/${d}
	@${CHMOD} 644 ${STAGEDIR}${DATADIR}/${d}/*
.endfor
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}
.for f in tutorial1 tutorial2
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${f}
.endfor

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
