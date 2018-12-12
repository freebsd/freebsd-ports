# $FreeBSD$

PORTNAME=	goxel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1-70
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g193eded
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Free and Open Source 3D Voxel Editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to build: sh: clang++: not found

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libglfw.so:graphics/glfw \
		libpng.so:graphics/png

USES=		compiler:c++11-lang pkgconfig scons
USE_GITHUB=	yes
GH_ACCOUNT=	guillaumechereau
USE_GNOME=	cairo gtk30
USE_GL=		gl

INSTALLS_ICONS=	yes
MAKE_ARGS=	clang=1 debug=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for SZ in 32 64 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/${SZ}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/goxel.png
.endfor
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
