PORTNAME=	wayland
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	graphics wayland
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper for Wayland

BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lang gl gnome pkgconfig qmake:norecursive \
		qt-dist:5,wayland xorg
USE_GL=		egl gl
USE_GNOME=	glib20
USE_QT=		core dbus gui declarative \
		buildtools_build qmake_build
USE_XORG=	x11 xcomposite

QT_BINARIES=	yes

.include <bsd.port.mk>
