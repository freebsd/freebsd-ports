# $FreeBSD$

PORTNAME=	qmake
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	5
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Makefile generator

USE_QT5=	# empty
USES=		compiler:c++11-lib pkgconfig shebangfix
SHEBANG_FILES=	util/harfbuzz/update-harfbuzz \
		util/unicode/x11/makeencodings \
		src/3rdparty/freetype/src/tools/afblue.pl \
		mkspecs/features/data/mac/objc_namespace.sh \
		mkspecs/macx-ios-clang/ios_destinations.sh \
		mkspecs/macx-ios-clang/ios_devices.pl
QT_DIST=	base
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
# Disable everything to install minimal qconfig.pri.
CONFIGURE_ARGS=	-no-accessibility -no-openssl -no-gui -no-cups \
		-no-iconv -no-icu -no-dbus -no-xcb -no-opengl \
		-no-glib -no-audio-backend -no-fontconfig \
		-no-gtk -no-xinput2 -no-xrender \
		-no-evdev -no-xkbcommon -no-alsa \
		-no-freetype -no-gif -no-harfbuzz -no-libjpeg \
		-no-libpng -no-pulseaudio -no-widgets
# Features yet to be removed from qconfig.pri.
TBR_CONFIG=	concurrent|inotify|xlib
QMAKESPEC=	${WRKSRC}/mkspecs/freebsd-${QMAKE_COMPILER}
INSTALL_TARGET=	sub-qmake-qmake-aux-pro-install_subtargets install_mkspecs

BROKEN_powerpc64=	fails to compile: error: unrecognized command line option -std=c++11

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

post-patch:
# Prevent qconfig.pri from being module dependent.
	@${REINPLACE_CMD} -E -e '/"\$$QT_CONFIG +(${TBR_CONFIG})"/ d' \
		${WRKSRC}/configure
# Clean up files created by patching
	@${RM} ${WRKSRC}/mkspecs/*/*.orig

post-build:
# Complete configure stage to generate *.pri files.
	@cd ${WRKSRC} && \
		${SETENV} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}
# Cleanup qmodule.pri to make it module agnostic.
	@${REINPLACE_CMD} -En -e '/^(CONFIG|QT_BUILD_PARTS|.*_DIR) / p' \
		${WRKSRC}/mkspecs/qmodule.pri

.include <bsd.port.mk>
