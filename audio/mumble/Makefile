# Created by: marius nuennerich
# $FreeBSD$

PORTNAME=	mumble
PORTVERSION=	1.2.19
PORTREVISION=	12
CATEGORIES=	audio

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Voice chat software primarily intended for use while gaming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS+=	libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libsndfile.so:audio/libsndfile \
		libboost_iostreams.so:devel/boost-libs \
		libprotoc.so:devel/protobuf \
		libopus.so:audio/opus

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USES=		compiler:c++11-lang cpe desktop-file-utils gmake pkgconfig qmake qt:4 ssl
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	mumble-voip
GH_PROJECT=	mumble celt-0.7.0:mumble_celt_0_7 celt-0.11.0:mumble_celt_0_11
GH_TAGNAME=	5a16cda:mumble_celt_0_7 e18de77:mumble_celt_0_11
GH_SUBDIR=	celt-0.7.0-src:mumble_celt_0_7 celt-0.11.0-src:mumble_celt_0_11
USE_QT=		gui svg iconengines_run xml sql network l10n \
		linguist_build moc_build rcc_build uic_build \
		opengl sql-sqlite3_run corelib
USE_LDCONFIG=	yes

USE_XORG=	ice xi x11
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

CONFIG=		no-server no-alsa no-speechd no-bundled-speex no-bundled-opus no-update \
		bundled-celt no-g15 no-pulseaudio no-xevie no-embed-qt-translations

QMAKE_ARGS=	"CONFIG+=${CONFIG}"

OPTIONS_DEFINE=	DBUS BONJOUR PORTAUDIO
OPTIONS_DEFAULT=	DBUS

DBUS_VARS_OFF=	CONFIG+=no-dbus
DBUS_USES=	qt:4
DBUS_USE=	QT=dbus

BONJOUR_DESC=		Bonjour support
BONJOUR_VARS_OFF=	CONFIG+=no-bonjour
BONJOUR_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

PORTAUDIO_VARS_OFF=	CONFIG+=no-portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

.include <bsd.port.pre.mk>

# PCH is broken on GCC
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

EXTRA_PATCHES=	${FILESDIR}/extrapatch-fix-build-boost-1.66:-p1

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/overlay_gl/overlay_gl.pro
	@${RM} ${WRKSRC}/plugins/manual/.qmake.cache

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.11.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.11.0
	${INSTALL_LIB} ${WRKSRC}/release/libcelt0.so.0.7.0 ${STAGEDIR}${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PORTVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumble.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmumble.so.1.2
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
