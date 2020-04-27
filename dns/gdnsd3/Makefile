# Created by: Allan Jude <allanjude@freebsd.org>
# $FreeBSD$

PORTNAME=	gdnsd
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://github.com/gdnsd/gdnsd/releases/download/v${PORTVERSION}/ \
		ZI \
		http://gdnsd.scaleengine.net/gdnsd/
PKGNAMESUFFIX=	3

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:devel/libev \
		libsodium.so:security/libsodium \
		liburcu.so:sysutils/liburcu

FETCH_ARGS=	-Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes
USES=		pkgconfig libtool tar:xz perl5 gmake
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS_INSTALL=	gdnsd-1.[0-9]* gdnsd2-2.[0-9]*

USE_RC_SUBR=	gdnsd

USERS?=		gdnsd
GROUPS?=	gdnsd

OPTIONS_DEFINE=	DOCS MAXMINDDB
OPTIONS_DEFAULT=MAXMINDDB

MAXMINDDB_DESC=		Enable GeoIP1 + GeoIP2 Support
MAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
CONFIGURE_ARGS+=--without-hardening
CFLAGS+=	-fstack-protector-strong -fexceptions -ftrapv
LDFLAGS+=	-Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${localstatedir}/lib/$${PACKAGE_NAME}|/var/db/${PORTNAME}|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gdnsd/geoip \
		${STAGEDIR}${PREFIX}/etc/gdnsd/zones \
		${STAGEDIR}/var/run/gdnsd

.include <bsd.port.post.mk>
