PORTNAME=	kdnssd
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	dns kde kde-frameworks

COMMENT=	Network service discovery using Zeroconf
MAINTAINER=	kde@FreeBSD.org

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base tools

OPTIONS_DEFAULT=	AVAHI
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNSRESPONDER
ZEROCONF_DESC=		Zeroconf (Bonjour) support

AVAHI_BUILD_DEPENDS=	${LOCALBASE}/include/avahi-common/defs.h:net/avahi-app
AVAHI_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Avahi

# libdns_sd.so is also provided by avahi-libdns.
# Add BUILD_DEPENDS to uniquely select mDNSResponder.
MDNSRESPONDER_BUILD_DEPENDS=	${LOCALBASE}/include/dns_sd.h:net/mDNSResponder
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_DNSSD

.include <bsd.port.mk>
