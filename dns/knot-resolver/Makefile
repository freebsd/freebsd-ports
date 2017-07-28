# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot-resolver
PORTVERSION=	1.3.1
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libknot.so:dns/knot2 \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv

CONFLICTS=	knot-1.* knot1-[0-6].*

MAKE_ARGS+=	PREFIX=${LOCALBASE}
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	MANDIR=${PREFIX}/man
MAKE_ARGS+=	PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig
MAKE_ARGS+=	lmdb_CFLAGS=-I${PREFIX}/include lmdb_LIBS=-llmdb

USES=		gmake libedit libtool pkgconfig tar:xz
USE_CSTD=	c99
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	COOKIES DNSTAP DOXYGEN GO MEMCACHED REDIS STATS

COOKIES_DESC=			cookies
COOKIES_LIB_DEPENDS=		libnettle.so:security/nettle

DNSTAP_DESC=			dnstap support
DNSTAP_LIB_DEPENDS=		libprotobuf.so:devel/protobuf \
				libprotobuf-c.so:devel/protobuf-c \
				libfstrm.so:devel/fstrm

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_MAKE_ARGS=		HAS_doxygen=yes
DOXYGEN_MAKE_ARGS_OFF=		HAS_doxygen=no

GO_DESC=			go
GO_BUILD_DEPENDS=		go>=1.5:lang/go

MEMCACHED_DESC=			memcached in-memory data-backend
MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHED_MAKE_ARGS=		HAS_libmemcached=yes
MEMCACHED_MAKE_ARGS_OFF=	HAS_libmemcached=no
MEMCACHED_PLIST_FILES=		lib/kdns_modules/kmemcached.so

REDIS_DESC=			redis in-memory data-backend
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_MAKE_ARGS=		HAS_hiredis=yes
REDIS_MAKE_ARGS_OFF=		HAS_hiredis=no
REDIS_PLIST_FILES=		lib/kdns_modules/redis.so

STATS_DESC=			stats
STATS_BUILD_DEPENDS=		luasocket:net/luasocket \
				luasec:security/luasec

USERS=		kresd
GROUPS=		kresd

PORTDOCS=	AUTHORS COPYING CodingStyle README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
