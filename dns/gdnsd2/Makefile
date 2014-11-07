# Created by: Allan Jude <allanjude@freebsd.org>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	2.1.0
CATEGORIES=	dns
MASTER_SITES=	https://github.com/blblack/gdnsd/releases/download/v${PORTVERSION}/ \
		http://mirrors.rit.edu/zi/ \
		http://gdnsd.scaleengine.net/gdnsd/
PKGNAMESUFFIX=	2

MAINTAINER=	zi@freebsd.org
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

FETCH_ARGS=	-Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes
USES=		pkgconfig libtool tar:xz perl5
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS_INSTALL=	gdnsd-1.[0-9]*

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

OPTIONS_DEFINE=	DOCS GEOIP URCU
OPTIONS_DEFAULT=GEOIP

GEOIP_DESC=		Enable GeoIP Support
GEOIP_RUN_DEPENDS=	GeoIP>=0:${PORTSDIR}/net/GeoIP

URCU_DESC=		Read-Copy-Update Support (Faster Zone Parsing)
URCU_CONFIGURE_WITH=	urcu
URCU_LIB_DEPENDS=	liburcu.so:${PORTSDIR}/sysutils/liburcu

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
