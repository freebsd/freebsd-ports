# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.2.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Mumble/${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Voice chat software primarily intended for use while gaming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libspeex.so:audio/speex \
		libsndfile.so:audio/libsndfile \
		libboost_iostreams.so:devel/boost-libs \
		libboost_python.so:devel/boost-python-libs \
		libprotoc.so:devel/protobuf \
		libopus.so:audio/opus

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USES=		compiler cpe gmake pkgconfig qmake
USE_LDCONFIG=	yes
USE_QT4=	gui svg iconengines_run xml sql network l10n \
		linguist_build moc_build rcc_build uic_build \
		opengl sql-sqlite3_run

USE_XORG=	ice
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-bundled-opus no-update \
		bundled-celt no-g15 no-portaudio no-pulseaudio no-xevie no-embed-qt-translations

QMAKE_ARGS=	"CONFIG+=${CONFIG}"

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
LIB_DEPENDS+=	libdns_sd.so:net/mDNSResponder
.endif

.include <bsd.port.pre.mk>

# PCH is broken on GCC
.if ${COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PORTVERSION}
	${LN} -s ${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so
	${LN} -s ${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.1
	${LN} -s ${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.1.2
	${MKDIR} ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.protocol ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.osx.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	@${MV} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.osx.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.png
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${STAGEDIR}${MANPREFIX}/man/man1/mumble.1

.include <bsd.port.post.mk>
