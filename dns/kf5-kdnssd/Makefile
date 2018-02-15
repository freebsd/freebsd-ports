# $FreeBSD$

PORTNAME=	kdnssd
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	dns kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction to system DNSSD features

USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core linguisttools network qmake_build

OPTIONS_DEFAULT=AVAHI
OPTIONS_RADIO=ZEROCONF
OPTIONS_RADIO_ZEROCONF=AVAHI MDNSRESPONDER
ZEROCONF_DESC=	Zeroconf (Bonjour) support

# Add BUILD_DEPENDS to uniquely select one or the other.
AVAHI_BUILD_DEPENDS=		${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h:net/avahi-libdns
AVAHI_LIB_DEPENDS=		libdns_sd.so:net/avahi-libdns
AVAHI_CMAKE_BOOL_OFF=		CMAKE_DISABLE_FIND_PACKAGE_Avahi
AVAHI_USE=			QT5=dbus

MDNSRESPONDER_BUILD_DEPENDS=	${LOCALBASE}/include/dns_sd.h:net/mDNSResponder
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_DNSSD
MDNSRESPONDER_USE=		QT5=dbus

.include <bsd.port.mk>
