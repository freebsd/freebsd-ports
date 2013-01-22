# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	asteroids3d
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/a3d/${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTNAME=	${PORTNAME:S/3d/3D/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		asteroids3d_icons.tbz:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	First-person shooter blowing up asteroids in 3D space

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		drm:${PORTSDIR}/graphics/libdrm \
		xcb:${PORTSDIR}/x11/libxcb

USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal autoheader
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	with_gamesdir="${PREFIX}/bin" with_gamedatadir="${DATADIR}"
USE_XORG=	x11 xau xdamage xdmcp xext xfixes xi xrandr xrender xxf86vm
USE_GL=		glut glu
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME:S/3d/3D/}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}_128.png \
		share/pixmaps/${PORTNAME}_48.png

PORTDATA=	*
PORTDOCS=	README.html

DESKTOP_ENTRIES="Asteroids3D" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}_48.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/autogen.sh

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/3d/3D/} ${PREFIX}/bin/${PORTNAME}

	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/src && ${COPYTREE_SHARE}  "*.ub *.ppm" ${DATADIR})

	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
