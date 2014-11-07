# Created by: Allan Jude <allanjude@freebsd.org>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	1.11.4
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	https://github.com/blblack/gdnsd/releases/download/v${PORTVERSION}/ \
		http://gdnsd.scaleengine.net/gdnsd/

MAINTAINER=	allanjude@freebsd.org
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

FETCH_ARGS=	-Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-rootdir=${LOCALBASE}/etc/gdnsd
USE_LDCONFIG=	yes
USES=		pkgconfig libtool tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS_INSTALL=	gdnsd2-2.[0-9]*

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

OPTIONS_DEFINE=	DOCS GEOIP URCU
OPTIONS_DEFAULT=	GEOIP

GEOIP_DESC=		Enable GeoIP Support
GEOIP_RUN_DEPENDS=	GeoIP>=0:${PORTSDIR}/net/GeoIP

URCU_DESC=		Read-Copy-Update Support (Faster Zone Parsing)
URCU_CONFIGURE_WITH=	urcu
URCU_LIB_DEPENDS=	liburcu.so:${PORTSDIR}/sysutils/liburcu

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libgdnsd.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_extmon.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_geoip.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_http_status.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_metafo.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_multifo.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_null.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_reflect.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_simplefo.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_static.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_tcp_connect.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugin_weighted.so
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdnsd/geoip
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdnsd/zones
	${MKDIR} ${STAGEDIR}/var/run/gdnsd

.include <bsd.port.mk>
