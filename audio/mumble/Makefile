# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Voice chat software primarily intended for use while gaming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libsndfile.so:audio/libsndfile \
		libboost_iostreams.so:devel/boost-libs \
		libprotoc.so:devel/protobuf \
		libopus.so:audio/opus

USES=		compiler:c++11-lang cpe desktop-file-utils gl gmake gnome pkgconfig python:build qmake qt:5 ssl xorg

PATCHVERSION=	${PORTVERSION}
MINORVERSION=	${PORTVERSION:R}
MAJORVERSION=	${PORTVERSION:R:R}

PLIST_SUB+=	PATCHVERSION="${PATCHVERSION}"
PLIST_SUB+=	MINORVERSION="${MINORVERSION}"
PLIST_SUB+=	MAJORVERSION="${MAJORVERSION}"

USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_TUPLE=	mumble-voip:mumble:${DISTVERSION} \
		mumble-voip:celt-0.7.0:5a16cda:mumble_celt_0_7/3rdparty/celt-0.7.0-src \
		mumble-voip:celt-0.11.0:e18de77:mumble_celt_0_11/3rdparty/celt-0.11.0-src \
		mumble-voip:mach_override:919148f:mumble_mach_override/3rdparty/mach-override-src \
		mumble-voip:minhook:9fbd087:mumble_minhook/3rdparty/minhook-src \
		mumble-voip:rnnoise:b30f2bb:mumble_rnnoise/3rdparty/rnnoise-src \
		mumble-voip:sbcelt:045493d:mumble_sbcelt/3rdparty/sbcelt-src \
		mumble-voip:mumble-theme:7dfb1e9:mumble_theme/themes/Mumble

USE_QT=		buildtools_build core gui l10n linguist_build network opengl sql sql-sqlite3_run svg widgets xml
USE_LDCONFIG=	yes

USE_XORG=	ice xi x11
USE_GL=		gl

CONFIG=		bundled-celt bundled-rnnoise no-bundled-opus no-bundled-speex no-bundled-speexdsp \
		no-embed-qt-translations no-g15 no-server no-update

QMAKE_ARGS=	"CONFIG+=${CONFIG}"

OPTIONS_DEFINE=	ALSA DBUS BONJOUR JACK PORTAUDIO PULSEAUDIO SPEECHD
OPTIONS_DEFAULT=	DBUS

ALSA_VARS_OFF=		CONFIG+=no-alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

DBUS_VARS_OFF=		CONFIG+=no-dbus
DBUS_USE=		QT=dbus

BONJOUR_DESC=		Bonjour support
BONJOUR_VARS_OFF=	CONFIG+=no-bonjour
BONJOUR_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

JACK_VARS_OFF=		CONFIG+=no-jackaudio
JACK_LIB_DEPENDS=	libjack.so:audio/jack

PORTAUDIO_VARS_OFF=	CONFIG+=no-portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

PULSEAUDIO_VARS_OFF=	CONFIG+=no-pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

SPEECHD_DESC=		Support for Speech Dispatcher
SPEECHD_VARS_OFF=	CONFIG+=no-speechd
SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

CONFIGURE_ENV+=	MUMBLE_PYTHON=${PYTHON_CMD}

.include <bsd.port.pre.mk>

# PCH is broken on GCC
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro
	@${RM} ${WRKSRC}/plugins/manual/.qmake.cache

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libmumble.so.${PATCHVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PATCHVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PATCHVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PATCHVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${MAJORVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PATCHVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${MINORVERSION}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.protocol ${STAGEDIR}${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.osx.installer.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.png
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${STAGEDIR}${MANPREFIX}/man/man1/mumble.1

.include <bsd.port.post.mk>
