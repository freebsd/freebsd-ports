# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.2.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Mumble/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A voice chat software primarily intended for use while gaming

LIB_DEPENDS+=	libspeex.so:${PORTSDIR}/audio/speex \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libboost_iostreams.so:${PORTSDIR}/devel/boost-libs \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libprotoc.so:${PORTSDIR}/devel/protobuf \
		libopus.so:${PORTSDIR}/audio/opus

USES=		gmake pkgconfig
USE_QT4=	gui svg iconengines_run xml sql network l10n \
		linguist_build qmake_build moc_build rcc_build uic_build \
		opengl sql-sqlite3_run

USE_XORG=	ice
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-bundled-opus no-update \
		bundled-celt no-g15 no-portaudio no-pulseaudio no-xevie no-embed-qt-translations

OPTIONS_DEFINE=	DBUS BONJOUR
OPTIONS_DEFAULT=	DBUS
BONJOUR_DESC=		Bonjour support

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDBUS}
CONFIG+=	no-dbus
.else
USE_QT4+=	dbus
.endif

.if ! ${PORT_OPTIONS:MBONJOUR}
CONFIG+=	no-bonjour
.else
LIB_DEPENDS+=	libdns_sd.so:${PORTSDIR}/net/mDNSResponder
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} QMAKESPEC=${QMAKESPEC} ${QMAKE} PREFIX=${PREFIX} main.pro "CONFIG+=${CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/libmumble.so.1.2.4 ${STAGEDIR}${PREFIX}/lib/libmumble.so.1.2.4
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${STAGEDIR}${PREFIX}/lib/libmumble.so
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${STAGEDIR}${PREFIX}/lib/libmumble.so.1
	${LN} -s ${PREFIX}/lib/libmumble.so.1.2.4 ${STAGEDIR}${PREFIX}/lib/libmumble.so.1.2
	${MKDIR} ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.protocol ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.osx.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	@${MV} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.osx.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.png
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${STAGEDIR}${MANPREFIX}/man/man1/mumble.1

.include <bsd.port.mk>
