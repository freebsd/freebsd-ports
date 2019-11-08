# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacmanarena
PORTVERSION=	0.15
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v0.0/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${DISTNAME:S/na/n-a/}.tar.bz2 \
		${PORTNAME:S/arena/-data/}-0.0.zip \
		${PORTNAME}_icons_1.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pacman clone in full 3D with a few surprises

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME:S/arena//}

USES=		gnome sdl
USE_SDL=	mixer net sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Pacman Arena" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|${DATADIR}|; \
		s|@datadir@/pacman|${DATADIR}|' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/arena//} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for d in gfx sfx
	@(cd ${WRKSRC}/../ && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
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
