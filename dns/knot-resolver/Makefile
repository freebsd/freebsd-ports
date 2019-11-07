# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	knot-resolver
DISTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns.company
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3+

BUILD_DEPENDS=	bash:shells/bash \
		git:devel/git
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libknot.so:dns/knot2-lib \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv
TEST_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

USES=		compiler:c11 compiler:c++11-lang libedit libtool meson \
		ncurses ninja pkgconfig shebangfix tar:xz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
LDFLAGS=	-L${LOCALBASE}/lib

SHEBANG_FILES=	scripts/bench.sh \
		scripts/build-in-obs.sh \
		scripts/coverage_c_combine.sh \
		scripts/coverage_env.sh \
		scripts/gen-cdefs.sh \
		scripts/get-date.sh \
		scripts/get-scanbuild-args.sh \
		scripts/luacov_gen_empty.sh \
		scripts/make-dev-archive.sh \
		scripts/make-distrofiles.sh \
		scripts/make-doc.sh \
		scripts/make-srpm.sh \
		scripts/run-pylint.sh \
		scripts/test-config.sh \
		scripts/test-integration-prepare.sh \
		scripts/update-root-hints.sh

CONFLICTS=	knot-1.* knot1-[0-6].*

MESON_ARGS=	--default-library=static \
		--mandir=${MANPREFIX} \
		--prefix=${LOCALBASE} \
		-Dsystemd=false
#MESON_ARGS+=	--libdir=${PREFIX}/lib
#MESON_ARGS+=	--pkg-config-path=${PREFIX}/libdata/pkgconfig
#MESON_ARGS+=	lmdb_CFLAGS=-I${PREFIX}/include lmdb_LIBS=-llmdb

OPTIONS_DEFINE=		DOCS DNSTAP DOXYGEN GO TRUSTANCHOR
OPTIONS_DEFAULT=	DOCS DNSTAP DOXYGEN GO

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
#DNSTAP_MAKE_ARGS_ON=		HAS_libprotobuf-c=yes HAS_libfstrm=yes
#DNSTAP_MAKE_ARGS_OFF=		HAS_libprotobuf-c=no  HAS_libfstrm=no
DNSTAP_PLIST_FILES=		lib/knot-resolver/kres_modules/dnstap.so

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
#DOXYGEN_MAKE_ARGS_ON=		HAS_doxygen=yes
#DOXYGEN_MAKE_ARGS_OFF=		HAS_doxygen=no

GO_DESC=			go
GO_USES=			go:no_targets
#GO_MAKE_ARGS_ON=		HAS_go=yes
#GO_MAKE_ARGS_OFF=		HAS_go=no

TRUSTANCHOR_DESC=		Trust anchor bootstrapping and stats
TRUSTANCHOR_USES=		lua
#TRUSTANCHOR_MAKE_ARGS_ON=	HAS_ltn12=yes HAS_ssl.https=yes
#TRUSTANCHOR_MAKE_ARGS_OFF=	HAS_ltn12=no  HAS_ssl.https=no
TRUSTANCHOR_BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}luasocket>=0:net/luasocket \
				${LUA_PKGNAMEPREFIX}luasec>=0:security/luasec

.include <bsd.port.options.mk>

USERS=		kresd
GROUPS=		kresd

PORTDOCS=	AUTHORS COPYING CodingStyle README.md

# check below list.
# libkres shouldn't have versioning anymore...
STRIP_TARGETS=	sbin/kresd			\
		sbin/kresc			\
		lib/libkres.so.7		\
		lib/kdns_modules/ahocorasick.so	\
		lib/kdns_modules/bogus_log.so	\
		lib/kdns_modules/cookies.so	\
		lib/kdns_modules/dnstap.so	\
		lib/kdns_modules/hints.so	\
		lib/kdns_modules/stats.so

pre-install-TEST-on: do-test

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.for STRIP_TGT in ${STRIP_TARGETS}
	if [ -f ${STAGEDIR}${PREFIX}/${STRIP_TGT} ]; then \
	    ${STRIP_CMD} ${STAGEDIR}${PREFIX}/${STRIP_TGT}; \
	fi
.endfor

.include <bsd.port.mk>
