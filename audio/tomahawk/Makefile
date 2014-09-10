# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomahawk
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Multi-source, social, and smart music player

LICENSE=	GPLv3

LIB_DEPENDS=	libattica.so:${PORTSDIR}/x11-toolkits/attica \
		libclucene-core.so:${PORTSDIR}/textproc/clucene \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libechonest.so:${PORTSDIR}/audio/libechonest \
		libjreen.so:${PORTSDIR}/net-im/libjreen \
		liblastfm.so:${PORTSDIR}/audio/liblastfm \
		libqca.so:${PORTSDIR}/devel/qca \
		libqjson.so:${PORTSDIR}/devel/qjson \
		libquazip.so:${PORTSDIR}/archivers/quazip \
		libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	qca-ossl>=2.0.0.b3_4:${PORTSDIR}/security/qca-ossl

CMAKE_ARGS+=	-DWITH_BREAKPAD:BOOL="OFF" \
		-DCLUCENE_CONFIG_PATH:PATH="${LOCALBASE}/share/clucene"
CXXFLAGS+=	-Wno-cast-align

GH_ACCOUNT=	tomahawk-player
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	7a869ef

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	QTWEETLIB
OPTIONS_DEFAULT=	GSTREAMER QTWEETLIB
OPTIONS_RADIO=	 PHONON
OPTIONS_RADIO_PHONON=	GSTREAMER VLC XINE
OPTIONS_SUB=	yes
QTWEETLIB_DESC=	Enable Twitter SIP plugin
VLC_DESC=	Multimedia support for VLC

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,} \
		PORTVERSION=${PORTVERSION}

USES=		cmake pkgconfig desktop-file-utils
USE_GITHUB=	yes
USE_LDCONFIG=	yes

USE_QT4=	dbus designer gui linguist_build moc_build \
		network phonon qmake_build qtestlib rcc_build \
		sql-sqlite2 svg uic_build xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQTWEETLIB}
LIB_DEPENDS+=	libQTweetLib.so:${PORTSDIR}/net/qtweetlib
.else
CMAKE_ARGS+=	-DWITH_QTweetLib:BOOL="OFF"
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	phonon-gstreamer>=4.6.3:${PORTSDIR}/multimedia/phonon-gstreamer
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	phonon-vlc>=0.6.1:${PORTSDIR}/multimedia/phonon-vlc
.endif

.if ${PORT_OPTIONS:MXINE}
RUN_DEPENDS+=	phonon-xine>=4.4.4_5:${PORTSDIR}/multimedia/phonon-xine
.endif

.include <bsd.port.mk>
