# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asteroids3d
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/a3d/${PORTVERSION}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTNAME=	${PORTNAME:S/3d/3D/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	First-person shooter blowing up asteroids in 3D space

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		tar:bzip2
USE_AUTOTOOLS=	aclocal autoheader
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	with_gamesdir="${PREFIX}/bin" with_gamedatadir="${DATADIR}"
USE_GL=		glut

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README.html
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Asteroids3D" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/3d/3D/} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/src && ${COPYTREE_SHARE}  "*.ub *.ppm" \
		 ${STAGEDIR}${DATADIR})

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
