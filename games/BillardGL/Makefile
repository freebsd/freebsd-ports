# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	BillardGL
PORTVERSION=	1.75
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}%20${PORTVERSION}/:game \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:game \
		${PORTNAME}-LP-010.zip:game \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME:L}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	OpenGL pool billiard simulation

LICENSE=	GPLv2

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_DOS2UNIX=	Makefile
USE_GMAKE=	yes
USE_XORG=	xmu xext x11 xi
USE_GL=		glut

DEPRECATED=	Unplayable, development ceased

EXPIRATION_DATE=2013-11-24

PORTDOCS=	README

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="BillardGL" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	LANG
OPTIONS_DEFAULT=LANG
LANG_DESC=	Install Language

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLANG}
PLIST_SUB+=	LANG=""
.else
PLIST_SUB+=	LANG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/BillardGL/|${DATADIR}/|' ${WRKSRC}/Namen.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.for d in Texturen
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MLANG}
	@${MKDIR} ${DATADIR}/lang
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-LP-010/*.lang ${DATADIR}/lang/
.endif

.include <bsd.port.mk>
