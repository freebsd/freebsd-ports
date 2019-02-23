# Created by: Allan Jude <allanjude@freebsd.org>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	2.4.2
CATEGORIES=	dns
MASTER_SITES=	https://github.com/gdnsd/gdnsd/releases/download/v${PORTVERSION}/ \
		ZI \
		http://gdnsd.scaleengine.net/gdnsd/
PKGNAMESUFFIX=	2

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:devel/libev
BUILD_DEPENDS=	ragel>0:devel/ragel

FETCH_ARGS=	-Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes
USES=		pkgconfig libtool tar:xz perl5 gmake
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS_INSTALL=	gdnsd-1.[0-9]* gdnsd3-3.[0-9]*

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

OPTIONS_DEFINE=	DOCS MAXMINDDB URCU
OPTIONS_DEFAULT=MAXMINDDB

MAXMINDDB_DESC=		Enable GeoIP1 + GeoIP2 Support
MAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

URCU_DESC=		Read-Copy-Update Support (Faster Zone Parsing)
URCU_CONFIGURE_WITH=	urcu
URCU_LIB_DEPENDS=	liburcu.so:sysutils/liburcu

post-patch:
	@${REINPLACE_CMD} -e 's|$${localstatedir}/lib/$${PACKAGE_NAME}|/var/db/${PORTNAME}|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libgdnsd.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_*.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdnsd/geoip \
		${STAGEDIR}${PREFIX}/etc/gdnsd/zones \
		${STAGEDIR}/var/run/gdnsd

.include <bsd.port.mk>
