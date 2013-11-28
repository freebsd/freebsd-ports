# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	capicity
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF/capitalism/Capi%20City/${PORTVERSION}/
DISTNAME=	CapiCity_${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Qt client for the Monopd server

LICENSE=	GPLv2

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/CapiCity_${PORTVERSION}

USES=		iconv qmake
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run \
		corelib gui network script xml

PORTDOCS=	README changelog

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 22x22 24x24 32x32 48x48 64x64

DESKTOP_ENTRIES="Capi City" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" false

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CapiCity ${PREFIX}/bin/${PORTNAME}

.for d in games images
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ts ${DATADIR})
.endif

.for s in ${ICON_SIZES}
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
