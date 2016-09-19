# $FreeBSD$

PORTNAME=	qmake
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Makefile generator

USE_QT5=	# empty
USES=		pkgconfig shebangfix
SHEBANG_FILES=	util/harfbuzz/update-harfbuzz \
		util/unicode/x11/makeencodings \
		src/3rdparty/freetype/src/tools/afblue.pl
QT_DIST=	base
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
# Disable everything to install minimal qconfig.pri.
CONFIGURE_ARGS=	-no-accessibility -no-openssl -no-gui -no-cups \
		-no-iconv -no-icu -no-dbus -no-xcb -no-opengl \
		-no-glib -no-audio-backend -no-fontconfig \
		-no-gtkstyle -no-xinput2 -no-xrender \
		-no-evdev -no-xkbcommon -no-alsa \
		-no-freetype -no-gif -no-harfbuzz -no-libjpeg \
		-no-libpng -no-pulseaudio -no-widgets
# Features yet to be removed from qconfig.pri.
TBR_CONFIG=	concurrent|inotify|xlib
QMAKESPEC=	${WRKSRC}/mkspecs/freebsd-${QMAKE_COMPILER}
INSTALL_TARGET=	install_qmake install_mkspecs

BROKEN_sparc64=		Fails to build: internal compiler error

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

post-patch:
# Prevent qconfig.pri from being module dependent.
	@${REINPLACE_CMD} -E -e '/"\$$QT_CONFIG +(${TBR_CONFIG})"/ d' \
		${WRKSRC}/configure
# Write the file location paths into mkspecs/common/freebsd.conf
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mkspecs/common/freebsd.conf
	@${REINPLACE_CMD} -e 's|unix.conf|freebsd.conf|' \
		${WRKSRC}/mkspecs/freebsd-icc/qmake.conf
# Add mkspec for g++. The clang is now the officially supported compiler for
# Qt>=5.6.0 on FreeBSD.
	@${MV} ${WRKSRC}/mkspecs/unsupported/freebsd-g++ \
		${WRKSRC}/mkspecs/freebsd-g++
	@${REINPLACE_CMD} -e 's|(../|(|g' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's|"../|"|g' \
		${WRKSRC}/mkspecs/freebsd-g++/qplatformdefs.h
# Clean up files created by patching
	@${RM} ${WRKSRC}/mkspecs/*/*.orig
	@${RM} -Rf ${WRKSRC}/mkspecs/unsupported/freebsd-g++46

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
