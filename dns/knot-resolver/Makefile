# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot-resolver
PORTVERSION=	1.3.3
PORTREVISION=	1
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

OPTIONS_DEFINE=	COOKIES DNSTAP DOXYGEN GO MEMCACHED REDIS TRUSTANCHOR

COOKIES_DESC=			cookies
COOKIES_LIB_DEPENDS=		libnettle.so:security/nettle
COOKIES_MAKE_ARGS_ON=		HAS_nettle=yes
COOKIES_MAKE_ARGS_OFF=		HAS_nettle=no
COOKIES_PLIST_FILES=		lib/kdns_modules/cookies.so      \
				include/libkres/alg_containers.h \
				include/libkres/alg_sha.h        \
				include/libkres/control.h        \
				include/libkres/helper.h         \
				include/libkres/lru_cache.h      \
				include/libkres/nonce.h

DNSTAP_DESC=			dnstap support
DNSTAP_LIB_DEPENDS=		libprotobuf.so:devel/protobuf \
				libprotobuf-c.so:devel/protobuf-c \
				libfstrm.so:devel/fstrm
DNSTAP_MAKE_ARGS_ON=		HAS_libprotobuf-c=yes HAS_libfstrm=yes
DNSTAP_MAKE_ARGS_OFF=		HAS_libprotobuf-c=no  HAS_libfstrm=no
DNSTAP_PLIST_FILES=		lib/kdns_modules/dnstap.so

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_MAKE_ARGS_ON=		HAS_doxygen=yes
DOXYGEN_MAKE_ARGS_OFF=		HAS_doxygen=no

GO_DESC=			go
GO_BUILD_DEPENDS=		go>=1.5:lang/go
GO_MAKE_ARGS_ON=		HAS_go=yes
GO_MAKE_ARGS_OFF=		HAS_go=no

MEMCACHED_DESC=			memcached in-memory data-backend
MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHED_MAKE_ARGS_ON=		HAS_libmemcached=yes
MEMCACHED_MAKE_ARGS_OFF=	HAS_libmemcached=no
MEMCACHED_PLIST_FILES=		lib/kdns_modules/kmemcached.so

REDIS_DESC=			redis in-memory data-backend
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_MAKE_ARGS_ON=		HAS_hiredis=yes
REDIS_MAKE_ARGS_OFF=		HAS_hiredis=no
REDIS_PLIST_FILES=		lib/kdns_modules/redis.so

TRUSTANCHOR_DESC=		Trust anchor bootstrapping and stats 
TRUSTANCHOR_USES=		lua
TRUSTANCHOR_MAKE_ARGS_ON=	HAS_ltn12=yes HAS_ssl.https=yes
TRUSTANCHOR_MAKE_ARGS_OFF=	HAS_ltn12=no  HAS_ssl.https=no
TRUSTANCHOR_BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}luasocket>=0:net/luasocket \
				${LUA_PKGNAMEPREFIX}luasec>=0:security/luasec

USERS=		kresd
GROUPS=		kresd

PORTDOCS=	AUTHORS COPYING CodingStyle README.md

STRIP_TARGETS=	sbin/kresd			\
		sbin/kresc			\
		lib/libkres.so.3		\
		lib/kdns_modules/cookies.so	\
		lib/kdns_modules/dnstap.so	\
		lib/kdns_modules/hints.so	\
		lib/kdns_modules/kmemcached.so	\
		lib/kdns_modules/stats.so

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.for STRIP_TGT in ${STRIP_TARGETS}
	if [ -f ${STAGEDIR}${PREFIX}/${STRIP_TGT} ]; then \
	    ${STRIP_CMD} ${STAGEDIR}${PREFIX}/${STRIP_TGT}; \
	fi
.endfor

.include <bsd.port.mk>
