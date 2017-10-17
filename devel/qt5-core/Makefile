# $FreeBSD$

PORTNAME=	core
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt core non-graphical module

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libpcre.so:devel/pcre

USE_GNOME=	glib20
USE_QT5=	qmake_build buildtools_build
QT_DIST=	base
HAS_CONFIGURE=	yes
# Disable (almost) everything to install minimal qconfig.h.
# -no-feature-* adds QT_NO_* (for features which have no switch or
# that need to be detected).
CONFIGURE_ARGS=	-no-accessibility -no-gif -no-libpng -no-libjpeg \
		-no-openssl -no-gui -no-widgets -no-cups \
		-no-iconv -no-dbus -no-opengl \
		-no-alsa -no-egl -no-evdev -no-feature-concurrent \
		-no-fontconfig -no-freetype -no-gtk -no-harfbuzz \
		-no-libudev -no-pulseaudio -no-xcb -no-xinput2 -no-xkb -no-xcb-xlib \
		-no-xkbcommon -no-xrender -no-xshape -no-xsync -no-libinput
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/corelib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	GLIB
QT_CONFIG=	glib icu

.include <bsd.port.pre.mk>

post-install:
# Allow qconfig.h to be customized by single ports.
	${AWK} 'BEGIN{print "#include <QtCore/qconfig-modules.h>"}{print}' \
		${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig.h > ${WRKDIR}/qconfig.h
	${MV} ${WRKDIR}/qconfig.h ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig.h

.include <bsd.port.post.mk>
