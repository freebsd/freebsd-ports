# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Mumble/${PORTVERSION}

MAINTAINER=	marius@nuenneri.ch
COMMENT=	A voice chat software primarily intended for use while gaming

LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex \
		sndfile:${PORTSDIR}/audio/libsndfile \
		boost_iostreams:${PORTSDIR}/devel/boost-libs \
		boost_python:${PORTSDIR}/devel/boost-python-libs \
		protoc:${PORTSDIR}/devel/protobuf \
		opus:${PORTSDIR}/audio/opus

USES=		gmake
USE_QT4=	gui svg iconengines_run xml sql network l10n \
		linguist_build qmake_build moc_build rcc_build uic_build \
		opengl sql-sqlite3_run

USE_XORG=	ice
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-bundled-opus no-update \
		bundled-celt no-g15 no-portaudio no-pulseaudio no-xevie no-embed-qt-translations

OPTIONS_DEFINE=	DBUS BONJOUR
OPTIONS_DEFAULT=	DBUS
BONJOUR_DESC=		Bonjour support

MAN1=		mumble.1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDBUS}
CONFIG+=	no-dbus
.else
USE_QT4+=	dbus
.endif

.if ! ${PORT_OPTIONS:MBONJOUR}
CONFIG+=	no-bonjour
.else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${QMAKE} PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/libmumble.so.1.2.4 ${PREFIX}/lib/libmumble.so.1.2.4
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${PREFIX}/lib/libmumble.so
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${PREFIX}/lib/libmumble.so.1
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${PREFIX}/lib/libmumble.so.1.2
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

.include <bsd.port.mk>
