# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot-resolver
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3

LIB_DEPENDS=	libknot.so:dns/knot2 \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle

CONFLICTS=	knot-1.* knot1-[0-6].*

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig
MAKE_ARGS+=	lmdb_CFLAGS=-I${LOCALBASE}/include lmdb_LIBS=-llmdb

USES=		gmake libtool pkgconfig tar:xz
USE_CSTD=	c99
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			DOXYGEN MEMCACHED REDIS
OPTIONS_DEFAULT=
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_MAKE_ARGS=		HAS_doxygen=yes
DOXYGEN_MAKE_ARGS_OFF=		HAS_doxygen=no
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

USERS=		kresd
GROUPS=		kresd

PORTDOCS=	AUTHORS COPYING CodingStyle README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
