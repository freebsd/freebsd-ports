# $FreeBSD$

PORTNAME=	qmake
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Makefile generator

USE_QT5=	# empty
QT_DIST=	base
REINPLACE_ARGS=	-i ""
HAS_CONFIGURE=	yes
# Disable everything to install minimal qconfig.pri.
CONFIGURE_ARGS=	-no-accessibility -no-openssl -no-gui -no-cups \
		-no-iconv -no-icu -no-dbus -no-xcb -no-opengl \
		-no-glib -no-audio-backend -no-fontconfig \
		-no-gtkstyle -no-xinput2 -no-xrender \
		-no-xkbcommon
# Features yet to be removed from qconfig.pri.
TBR_CONFIG=	alsa|concurrent|.*freetype|.*gif|.*gui|.*harfbuzz|inotify|.*jpeg|.*pkg-config|.*png|pulseaudio|.*widgets|xlib
QMAKESPEC=	${WRKSRC}/mkspecs/freebsd-${QMAKE_COMPILER}
INSTALL_TARGET=	install_qmake install_mkspecs

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

.include <bsd.port.pre.mk>

# Needs bsd.port.pre.mk to override -dont-process from bsd.qt.mk.
CONFIGURE_ARGS+=-process

post-patch:
# Prevent qconfig.pri from being module dependent.
	@${REINPLACE_CMD} -E -e '/"\$$QT_CONFIG +(${TBR_CONFIG})"/ d' \
		${WRKSRC}/configure

	@${RM} ${WRKSRC}/mkspecs/*/*.orig

	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/mkspecs/common/freebsd.conf
	@${REINPLACE_CMD} -e 's|unix.conf|freebsd.conf|' \
		${WRKSRC}/mkspecs/freebsd-icc/qmake.conf

# Add mkspec for Clang.
	@${CP} -a ${WRKSRC}/mkspecs/freebsd-g++ \
		${WRKSRC}/mkspecs/freebsd-clang
	@${REINPLACE_CMD} -e 's|g++|clang|g' \
		-e '/gcc-base-unix.conf/d' \
		${WRKSRC}/mkspecs/freebsd-clang/qmake.conf

	@${RM} -Rf ${WRKSRC}/mkspecs/freebsd-g++46

post-build:
# Complete configure stage to generate *.pri files.
	@cd ${WRKSRC} && \
		${SETENV} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
# Cleanup qmodule.pri to make it module agnostic.
	@${REINPLACE_CMD} -En -e '/^(CONFIG|QT_BUILD_PARTS|.*_DIR) / p' \
		${WRKSRC}/mkspecs/qmodule.pri

.include <bsd.port.post.mk>
