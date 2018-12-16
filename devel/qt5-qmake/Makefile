# $FreeBSD$

PORTNAME=	qmake
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Makefile generator

USES=		compiler:c++11-lib gmake pkgconfig \
		python:build qmake:no_env qt-dist:5,base shebangfix
SHEBANG_FILES=	util/harfbuzz/update-harfbuzz \
		util/unicode/x11/makeencodings \
		src/3rdparty/freetype/src/tools/afblue.pl \
		mkspecs/features/data/mac/objc_namespace.sh \
		mkspecs/features/uikit/devices.py \
		mkspecs/features/uikit/device_destinations.sh

REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
# Disable everything to install minimal qconfig.pri.
CONFIGURE_ARGS=	-no-accessibility -no-openssl -no-gui -no-cups \
		-no-iconv -no-icu -no-dbus -no-xcb -no-opengl \
		-no-glib -no-fontconfig \
		-no-gtk \
		-no-evdev -no-xkbcommon \
		-no-freetype -no-gif -no-harfbuzz -no-libjpeg \
		-no-libpng -no-widgets
QMAKESPEC=	freebsd-${QMAKE_COMPILER}
INSTALL_TARGET=	sub-qmake-qmake-aux-pro-install_subtargets install_mkspecs

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

post-patch:
# Clean up files created by patching
	@${RM} ${WRKSRC}/mkspecs/*/*.orig

post-build:
# Complete configure stage to generate *.pri files.
	cd ${WRKSRC} && \
		${SETENV} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" BUILD_QMAKE=1 \
		${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
