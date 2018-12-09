# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	knot-resolver
DISTVERSION=	3.1.0
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns.company
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		git:devel/git
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libknot.so:dns/knot2-lib \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv
TEST_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

USES=		gmake libedit libtool ncurses pkgconfig shebangfix tar:xz

SHEBANG_FILES=	scripts/coverage_env.sh
USE_LDCONFIG=	yes

CONFLICTS=	knot-1.* knot1-[0-6].*

MAKE_ARGS+=	PREFIX=${LOCALBASE}
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	MANDIR=${PREFIX}/man
MAKE_ARGS+=	PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig
MAKE_ARGS+=	lmdb_CFLAGS=-I${PREFIX}/include lmdb_LIBS=-llmdb

OPTIONS_DEFINE=	DOCS DNSTAP DOXYGEN GO TRUSTANCHOR

# COOKIES will come return/reworked to reflect IETF dnsop group development
#COOKIES_DESC=			cookies
#COOKIES_LIB_DEPENDS=		libnettle.so:security/nettle
#COOKIES_MAKE_ARGS_ON=		HAS_nettle=yes
#COOKIES_MAKE_ARGS_OFF=		HAS_nettle=no
#COOKIES_PLIST_FILES=		lib/kdns_modules/cookies.so      \
#				include/libkres/alg_containers.h \
#				include/libkres/alg_sha.h        \
#				include/libkres/control.h        \
#				include/libkres/helper.h         \
#				include/libkres/lru_cache.h      \
#				include/libkres/nonce.h

DNSTAP_DESC=			dnstap support
DNSTAP_LIB_DEPENDS=		libprotobuf.so:devel/protobuf \
				libprotobuf-c.so:devel/protobuf-c \
				libfstrm.so:devel/fstrm
DNSTAP_MAKE_ARGS_ON=		HAS_libprotobuf-c=yes HAS_libfstrm=yes
DNSTAP_MAKE_ARGS_OFF=		HAS_libprotobuf-c=no  HAS_libfstrm=no
DNSTAP_PLIST_FILES=		lib/kdns_modules/dnstap.so

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_MAKE_ARGS_ON=		HAS_doxygen=yes
DOXYGEN_MAKE_ARGS_OFF=		HAS_doxygen=no

GO_DESC=			go
GO_BUILD_DEPENDS=		go>=1.5:lang/go
GO_MAKE_ARGS_ON=		HAS_go=yes
GO_MAKE_ARGS_OFF=		HAS_go=no

TRUSTANCHOR_DESC=		Trust anchor bootstrapping and stats
TRUSTANCHOR_USES=		lua
TRUSTANCHOR_MAKE_ARGS_ON=	HAS_ltn12=yes HAS_ssl.https=yes
TRUSTANCHOR_MAKE_ARGS_OFF=	HAS_ltn12=no  HAS_ssl.https=no
TRUSTANCHOR_BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}luasocket>=0:net/luasocket \
				${LUA_PKGNAMEPREFIX}luasec>=0:security/luasec

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1120000
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	libknot (installed by knot2) is broken on 11.2 at i386
.endif

USERS=		kresd
GROUPS=		kresd

PORTDOCS=	AUTHORS COPYING CodingStyle README.md

STRIP_TARGETS=	sbin/kresd			\
		sbin/kresc			\
		lib/libkres.so.7		\
		lib/kdns_modules/ahocorasick.so	\
		lib/kdns_modules/bogus_log.so	\
		lib/kdns_modules/cookies.so	\
		lib/kdns_modules/dnstap.so	\
		lib/kdns_modules/hints.so	\
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
