# Created by: Allan Jude <ports@scaleengine.com>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	1.10.0
CATEGORIES=	dns
MASTER_SITES=	http://downloads.gdnsd.net/ \
		http://gdnsd.scaleengine.net/gdnsd/

MAINTAINER=	ports@scaleengine.com
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

OPTIONS_DEFINE=	GEOIP

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		pkgconfig

MAN1=		gdnsd_geoip_test.1
MAN3=		gdnsd-plugin-api.3
MAN5=		gdnsd.config.5 gdnsd.zonefile.5
MAN8=		gdnsd.8 gdnsd-plugin-simplefo.8 gdnsd-plugin-multifo.8 \
		gdnsd-plugin-metafo.8 gdnsd-plugin-geoip.8 \
		gdnsd-plugin-weighted.8 gdnsd-plugin-extmon.8
MANCOMPRESSED=	no

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIP}
RUN_DEPENDS+=	${LOCALBASE}/share/GeoIP/GeoIP.dat:${PORTSDIR}/net/GeoIP
.endif

post-install:
	${MKDIR} ${PREFIX}/var/run/gdnsd
	${MKDIR} ${PREFIX}/etc/gdnsd/zones
	${TOUCH} ${PREFIX}/etc/gdnsd/zones/.keep-me

.include <bsd.port.mk>
