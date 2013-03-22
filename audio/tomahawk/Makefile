# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomahawk
PORTVERSION=	0.6.0
#PORTREVISION=	0
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Multi-source, social, and smart music player

LICENSE=	GPLv3

BUILD_DEPENDS=	clucene>=2.3.3.4:${PORTSDIR}/textproc/clucene
LIB_DEPENDS=	attica:${PORTSDIR}/x11-toolkits/attica \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		echonest:${PORTSDIR}/audio/libechonest \
		jreen:${PORTSDIR}/net-im/libjreen \
		lastfm:${PORTSDIR}/audio/liblastfm \
		qca:${PORTSDIR}/devel/qca \
		qjson:${PORTSDIR}/devel/qjson \
		quazip:${PORTSDIR}/archivers/quazip \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	phonon-vlc>=0.6.1:${PORTSDIR}/multimedia/phonon-vlc \
		phonon-gstreamer>=4.6.3:${PORTSDIR}/multimedia/phonon-gstreamer \
		qca-ossl>=2.0.0.b3_4:${PORTSDIR}/security/qca-ossl

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING="Release" \
		-DWITH_BREAKPAD:BOOL="OFF" \
		-DWITH_BUILD:STRING="Release"

GH_ACCOUNT=	tomahawk-player
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${DISTVERSION}
GH_COMMIT=	2b8cc4f

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	QTWEETLIB
OPTIONS_DEFAULT=	QTWEETLIB
QTWEETLIB_DESC=	Enable Twitter SIP plugin

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

USE_QT4=	dbus designer gui linguist_build moc_build \
		network phonon qmake_build qtestlib rcc_build \
		sql-sqlite2 svg uic_build xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQTWEETLIB}
LIB_DEPENDS+=	QTweetLib:${PORTSDIR}/net/qtweetlib
.else
CMAKE_ARGS+=	-DWITH_QTweetLib:BOOL="OFF"
.endif

.include <bsd.port.mk>
