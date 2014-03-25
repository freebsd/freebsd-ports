# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bomns3
PORTVERSION=	0.0.0
CATEGORIES=	games

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Old-school bomb-dropping Deathmatch

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee
RUN_DEPENDS=	dejavu>0:${PORTSDIR}/x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_PROJECT=	bomns3
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	16611e5

USES=		gmake pkgconfig
USE_SDL=	image mixer sdl ttf
USE_GNOME=	glib20

PORTDOCS=	AUTHORS README.md
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Bomns3" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e \
	's|/usr/share/fonts/truetype/ttf-dejavu/|${LOCALBASE}/lib/X11/fonts/dejavu/|' \
		${WRKSRC}/src/sdl/common.vala
	@${REINPLACE_CMD} -e 's|gee-1.0|gee-0.8|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} gfx ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/gfx/bomns3-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
