# $FreeBSD$

PORTNAME=	wayland
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper for Wayland

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lang gl gnome pkgconfig qmake:norecursive \
		qt-dist:5,wayland
USE_GL=		egl gl
USE_GNOME=	glib20
USE_QT=		core dbus gui declarative \
		buildtools_build qmake_build
USE_XORG=       x11 xcomposite

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
