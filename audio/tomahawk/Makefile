# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomahawk
PORTVERSION=	0.7.0
#PORTREVISION=	0
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Multi-source, social, and smart music player

LICENSE=	GPLv3

LIB_DEPENDS=	attica:${PORTSDIR}/x11-toolkits/attica \
		clucene-core:${PORTSDIR}/textproc/clucene \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		echonest:${PORTSDIR}/audio/libechonest \
		jreen:${PORTSDIR}/net-im/libjreen \
		lastfm:${PORTSDIR}/audio/liblastfm \
		qca:${PORTSDIR}/devel/qca \
		qjson:${PORTSDIR}/devel/qjson \
		quazip:${PORTSDIR}/archivers/quazip \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	qca-ossl>=2.0.0.b3_4:${PORTSDIR}/security/qca-ossl

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING="Release" \
		-DWITH_BREAKPAD:BOOL="OFF" \
		-DWITH_BUILD:STRING="Release" \
		-DCLUCENE_CONFIG_PATH:PATH="${LOCALBASE}/share/clucene"

GH_ACCOUNT=	tomahawk-player
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	7a869ef

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	QTWEETLIB
OPTIONS_DEFAULT=	GSTREAMER QTWEETLIB
OPTIONS_RADIO=	 PHONON
OPTIONS_RADIO_PHONON=	GSTREAMER VLC XINE
QTWEETLIB_DESC=	Enable Twitter SIP plugin
VLC_DESC=	Multimedia support for VLC

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,} \
		PORTVERSION=${PORTVERSION}

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

USE_QT4=	dbus designer gui linguist_build moc_build \
		network phonon qmake_build qtestlib rcc_build \
		sql-sqlite2 svg uic_build xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQTWEETLIB}
LIB_DEPENDS+=	QTweetLib:${PORTSDIR}/net/qtweetlib
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
