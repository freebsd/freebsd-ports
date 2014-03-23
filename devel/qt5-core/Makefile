# $FreeBSD$

PORTNAME=	core
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt core non-graphical module

LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		libpcre.so:${PORTSDIR}/devel/pcre

USE_GNOME=	glib20
USE_QT5=	qmake_build buildtools_build
QT_DIST=	base
HAS_CONFIGURE=	yes
# Disable (almost) everything to install minimal qconfig.h.
# -no-feature-* adds QT_NO_* (for features which have no switch or
# that need to be detected).
CONFIGURE_ARGS=	-no-accessibility -no-gif -no-libpng -no-libjpeg \
		-no-openssl -no-gui -no-widgets -no-cups \
		-no-iconv -no-dbus -no-xcb -no-opengl \
		-no-feature-glib -no-feature-alsa \
		-no-feature-concurrent -no-feature-evdev \
		-no-fontconfig -no-freetype \
		-no-gtkstyle -no-feature-inotify -no-feature-libudev \
		-no-feature-pulseaudio -no-feature-xcb -no-xinput \
		-no-xkb -no-xrender -no-xshape -no-xsync -no-xvideo \
		-no-xkbcommon -no-harfbuzz
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/corelib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	GLIB
QT_CONFIG=	glib icu

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/3rdparty/harfbuzz/src/harfbuzz*.h \
		${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/${QT5_VERSION:C/-.*//}/QtCore/private
# Allow qconfig.h to be customized by single ports.
	${REINPLACE_CMD} -i "" '1 s|.*|#include <QtCore/qconfig-modules.h>|' \
		${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig.h

.include <bsd.port.post.mk>
