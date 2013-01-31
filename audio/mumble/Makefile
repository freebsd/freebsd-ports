# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Mumble/${PORTVERSION}

MAINTAINER=	marius@nuenneri.ch
COMMENT=	A voice chat software primarily intended for use while gaming

LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		boost_iostreams:${PORTSDIR}/devel/boost-libs \
		boost_python:${PORTSDIR}/devel/boost-python-libs \
		protoc:${PORTSDIR}/devel/protobuf

USE_GMAKE=	yes
USE_QT4=	gui svg iconengines_run xml sql network l10n \
		linguist_build qmake_build moc_build rcc_build uic_build \
		opengl sql-sqlite3_run

USE_XORG=	ice
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-update \
		no-g15 no-portaudio no-pulseaudio no-xevie no-embed-qt-translations

OPTIONS=	DBUS "Enable D-Bus support" on \
		BONJOUR "Enable Bonjour support" off \
		MUMBLE11X "Enable mumble 1.1 support" off \
		SYSCELT "Use system CELT libraries" off \

MAN1=		mumble.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.x
.endif

.if defined(WITHOUT_DBUS)
CONFIG+=	no-dbus
.else
USE_QT4+=	dbus
.endif

.if defined(WITHOUT_SYSCELT)
CONFIG+=	bundled-celt
PLIST_SUB+=	BUNDLECELT=""
.else
CONFIG+=	no-bundled-celt
PLIST_SUB+=	BUNDLECELT="@comment "
LIB_DEPENDS+=	celt0.2:${PORTSDIR}/audio/celt
.endif

.if defined(WITHOUT_BONJOUR)
CONFIG+=	no-bonjour
.else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.endif

.if defined(WITHOUT_MUMBLE11X)
CONFIG+=	no-11x
PLIST_SUB+=	MUMBLE11X="@comment "
.else
PLIST_SUB+=	MUMBLE11X=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro
	# Fix with celt 0.11
.if !defined(WITHOUT_SYSCELT)
	@${REINPLACE_CMD} -e 's/CELT_SET_VBR_RATE/CELT_SET_BITRATE/g' ${WRKSRC}/src/mumble/AudioInput.cpp
.endif

do-configure:
.if defined(WITHOUT_SYSCELT)
	cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${QMAKE} PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}"
.else
	cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${QMAKE} PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}" "DEFINES+=FREEBSD_SYSTEM_CELT=1"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${PREFIX}/bin
.if defined(WITHOUT_SYSCELT)
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${PREFIX}/lib/libcelt-mumble.so.0.7.0
.endif
.if !defined(WITHOUT_MUMBLE11X)
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble11x ${PREFIX}/bin
.endif
	${MKDIR} ${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.protocol ${PREFIX}/share/services
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/share/icons/hicolor/128x128/apps ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.osx.png ${PREFIX}/share/icons/hicolor/128x128/apps
	@${MV} ${PREFIX}/share/icons/hicolor/128x128/apps/mumble.osx.png ${PREFIX}/share/icons/hicolor/128x128/apps/mumble.png
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
