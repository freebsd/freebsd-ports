# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomahawk
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-source, social, and smart music player

LICENSE=	GPLv3

BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash \
		websocketpp>=0.4.0:devel/websocketpp
RUN_DEPENDS=	phonon-vlc>=0.6.1:multimedia/phonon-vlc
LIB_DEPENDS=	libattica.so:x11-toolkits/attica \
		liblucene++.so:textproc/luceneplusplus \
		libboost_thread.so:devel/boost-libs \
		libechonest.so:audio/libechonest \
		libgnutls.so:security/gnutls \
		libjreen.so:net-im/libjreen \
		liblastfm.so:audio/liblastfm \
		libqca.so:devel/qca \
		libqjson.so:devel/qjson \
		libqtkeychain.so:security/qtkeychain-qt4 \
		libquazip.so:archivers/quazip \
		libtag.so:audio/taglib

CMAKE_ARGS=	-DBUILD_RELEASE="ON"
CXXFLAGS+=	-Wno-cast-align -I${LOCALBASE}/include
LDFLAGS+=	-lz

GH_ACCOUNT=	tomahawk-player

TELEPATHY_LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4
TELEPATHY_DESC=	Configure Telepathy Settings
TELEPATHY_USES=	kde:4
TELEPATHY_USE=	KDE=kdelibs,automoc4

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
