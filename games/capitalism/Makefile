# Created by:	nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	capitalism
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.linux-ecke.de/Capitalism/packages/0.5/
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Qt client for the Monopd server

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xrender
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats \
		corelib gui network script xml
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README changelog

WRKSRC=		${WRKDIR}/Capitalism_${PORTVERSION}
ICON_SIZES=	16x16 22x22 24x24 32x32 48x48 64x64

DESKTOP_ENTRIES="Capitalism" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" ${FALSE}

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-configure:
	@${REINPLACE_CMD} 's|-O2 -Wall -W||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Capitalism ${PREFIX}/bin/${PORTNAME}

.for d in games images ts
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
