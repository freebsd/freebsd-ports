PORTNAME=	goxel
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free and open-source 3D voxel editor
WWW=		https://goxel.xyz/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libpng.so:graphics/png

USES=		compiler:c++17-lang gl gnome pkgconfig scons
USE_GITHUB=	yes
GH_ACCOUNT=	guillaumechereau
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30

MAKE_ARGS=	mode=release werror=false

DESKTOP_ENTRIES="Goxel" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Graphics;3DGraphics;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for n in 16 32 64 128 512 256 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/${n}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps/goxel.png
.endfor

.include <bsd.port.mk>
