# $FreeBSD$

PORTNAME=	kdnssd
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	dns kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction to system DNSSD features

OPTIONS_DEFAULT=AVAHI
OPTIONS_RADIO=ZEROCONF
OPTIONS_RADIO_ZEROCONF=AVAHI MDNSRESPONDER
ZEROCONF_DESC=	Zeroconf (Bonjour) support

AVAHI_CLAGS+=			-I${LOCALBASE}/include/avahi-compat-libdns_sd
AVAHI_LIB_DEPENDS=		libdns_sd.so:net/avahi-libdns
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

# TODO: options to depend on avahi and/or dnssd
USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core dbus linguisttools network qmake_build

.include <bsd.port.mk>
