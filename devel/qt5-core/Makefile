# $FreeBSD$

PORTNAME=	core
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt core non-graphical module

LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libicui18n.so:devel/icu \
		libpcre2-posix.so:devel/pcre2 \
		libzstd.so:archivers/zstd

USES=		compiler:c++11-lang gnome qmake:no_env qt-dist:5,base
USE_GNOME=	glib20
USE_QT=		qmake_build buildtools_build
HAS_CONFIGURE=	yes
# Disable (almost) everything to install minimal qconfig.h.
# -no-feature-* adds QT_NO_* (for features which have no switch or
# that need to be detected).
CONFIGURE_ARGS=	-no-accessibility -no-gif -no-libpng -no-libjpeg \
		-no-openssl -no-gui -no-widgets -no-cups \
		-no-iconv -no-dbus -no-opengl \
		-no-egl -no-evdev \
		-no-fontconfig -no-freetype -no-gtk -no-harfbuzz \
		-no-libudev -no-xcb -no-xcb-xlib \
		-no-xkbcommon -no-libinput

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/corelib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_BINARIES=	yes
QT_DEFINES=	GLIB
QT_CONFIG=	glib icu

MORE_WRKSRCS=	src/tools/bootstrap src/corelib src/tools/qlalr

.include <bsd.port.pre.mk>
# FreeBSD base gained /etc/os-release in r354922, which
# corresponds to __FreeBSD_version 1300060
.if ${OSVERSION} < 1300060
RUN_DEPENDS+=	etc_os-release>0:sysutils/etc_os-release
post-patch:
	${REINPLACE_CMD}  -e '/readEtcFile/s|/etc/os-release|${LOCALBASE}/etc/os-release|g' \
		${WRKSRC}/src/corelib/global/qglobal.cpp
.endif

post-configure:
.for d in ${MORE_WRKSRCS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

pre-build:
.for d in ${MORE_WRKSRCS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
# Allow qconfig.h to be customized by single ports.
	${AWK} 'BEGIN{print "#include <QtCore/qconfig-modules.h>"}{print}' \
		${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig.h > ${WRKDIR}/qconfig.h
# Manually install qlalr
	cd ${WRKSRC}/src/tools/qlalr && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
# Cleanup qconfig.h and remove stray '#define QT_NO_FOO'
	${REINPLACE_CMD} "/#define QT_NO_/d" ${WRKDIR}/qconfig.h
	${MV} ${WRKDIR}/qconfig.h ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtCore/qconfig.h

.include <bsd.port.post.mk>
