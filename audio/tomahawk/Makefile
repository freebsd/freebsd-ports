# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomahawk
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-source, social, and smart music player

LICENSE=	GPLv3

BUILD_DEPENDS=	google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash \
		websocketpp>=0.4.0:${PORTSDIR}/devel/websocketpp
RUN_DEPENDS=	phonon-vlc>=0.6.1:${PORTSDIR}/multimedia/phonon-vlc
LIB_DEPENDS=	libattica.so:${PORTSDIR}/x11-toolkits/attica \
		liblucene++.so:${PORTSDIR}/textproc/luceneplusplus \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libechonest.so:${PORTSDIR}/audio/libechonest \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libjreen.so:${PORTSDIR}/net-im/libjreen \
		liblastfm.so:${PORTSDIR}/audio/liblastfm \
		libqca.so:${PORTSDIR}/devel/qca \
		libqjson.so:${PORTSDIR}/devel/qjson \
		libqtkeychain.so:${PORTSDIR}/security/qtkeychain-qt4 \
		libquazip.so:${PORTSDIR}/archivers/quazip \
		libtag.so:${PORTSDIR}/audio/taglib

CMAKE_ARGS=	-DBUILD_RELEASE="ON"
CXXFLAGS+=	-Wno-cast-align -I${LOCALBASE}/include

GH_ACCOUNT=	tomahawk-player

TELEPATHY_LIB_DEPENDS=	libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4
TELEPATHY_DESC=	Configure Telepathy Settings
TELEPATHY_USE_KDE4=	kdelibs automoc4

INSTALLS_ICONS=	yes

OPTIONS_DEFAULT=
OPTIONS_DEFINE=	TELEPATHY
OPTIONS_SUB=	yes

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,^${PREFIX}/,,} \
		PORTVERSION=${PORTVERSION}

USES=		cmake compiler:c++11-lib desktop-file-utils pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	dbus designer gui linguist_build moc_build \
		network phonon qmake_build qtestlib rcc_build \
		sql-sqlite2 svg uic_build xml

.include <bsd.port.mk>
