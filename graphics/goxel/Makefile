# $FreeBSD$

PORTNAME=	goxel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Free and Open Source 3D Voxel Editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libglfw.so:graphics/glfw \
		libpng.so:graphics/png

USES=		compiler:c++11-lang pkgconfig scons gnome gl
USE_GITHUB=	yes
GH_ACCOUNT=	guillaumechereau
USE_GNOME=	cairo gtk30
USE_GL=		gl

INSTALLS_ICONS=	yes
MAKE_ARGS=	debug=0 werror=0
DESKTOP_ENTRIES="Goxel" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Graphics;3DGraphics;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for SZ in 32 64 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/${SZ}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/goxel.png
.endfor

.include <bsd.port.mk>
