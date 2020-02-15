# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	knot-resolver
DISTVERSION=	5.0.1
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns.company
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		cmocka>=1.1.1:sysutils/cmocka \
		flake8:devel/py-flake8@${PY_FLAVOR} \
		luacheck:devel/lua-luacheck

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libknot.so:dns/knot2-lib \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit-openresty \
		libuv.so:devel/libuv

USES=		compiler:c11 compiler:c++11-lang libedit libtool meson \
		ncurses ninja pkgconfig python shebangfix tar:xz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

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
		scripts/obs-build.sh \
		scripts/run-pylint.sh \
		scripts/test-config.sh \
		scripts/test-integration-prepare.sh \
		scripts/update-root-hints.sh

CONFLICTS=	knot-1.* knot1-[0-6].*

MESON_ARGS=	--buildtype=release \
		--default-library=static \
		--prefix=${LOCALBASE} \
		-Duser=${USERS} \
		-Dgroup=${GROUPS} \
		-Dinstall_kresd_conf=enabled \
		-Dclient=enabled \
		-Dutils=enabled \
		-Dinstall_root_keys=enabled \
		-Dkeyfile_default=${ETCDIR}/root.keys \
		-Dmanaged_ta=enabled \
		-Droot_hints=${ETCDIR}/root.hints \
		-Dunit_tests=enabled

#		--libdir=${PREFIX}/lib
#		--pkg-config-path=${PREFIX}/libdata/pkgconfig
#		lmdb_CFLAGS=-I${PREFIX}/include lmdb_LIBS=-llmdb
#		-Dlmdb_CFLAGS=-I${PREFIX}/include \	# doesn't help
#		-Dlmdb_LIBS=-llmdb			# doesn't help
#		-Dconfig_tests=enabled \		# complains about missing cqueues lua package
#		-Dextra_tests=enabled \			# also requires -Dsendmmsg=disabled

OPTIONS_DEFINE=		DOCS DNSTAP DOXYGEN TRUSTANCHOR
OPTIONS_DEFAULT=	DOCS DNSTAP DOXYGEN

# docs/meson.build wants python2 or python3 - not -for example- python3.7
# So this currently is partially broken:
#DOCS_MESON_ON=			-Ddoc=enabled

DNSTAP_DESC=			dnstap support
DNSTAP_LIB_DEPENDS=		libprotobuf.so:devel/protobuf \
				libprotobuf-c.so:devel/protobuf-c \
				libfstrm.so:devel/fstrm
DNSTAP_PLIST_FILES=		lib/knot-resolver/kres_modules/dnstap.so
DNSTAP_MESON_ON=		-Ddnstap=enabled
DNSTAP_MESON_OFF=		-Ddnstap=disabled

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

TRUSTANCHOR_DESC=		Trust anchor bootstrapping and stats
TRUSTANCHOR_USES=		lua
TRUSTANCHOR_BUILD_DEPENDS=	${LUA_PKGNAMEPREFIX}luasocket>=0:net/luasocket \
				${LUA_PKGNAMEPREFIX}luasec>=0:security/luasec

.include <bsd.port.options.mk>

USERS=		kresd
GROUPS=		${USERS}

PORTDOCS=	AUTHORS COPYING CodingStyle NEWS README.md

STRIP_TARGETS=	sbin/kresd \
		sbin/kresc \
		lib/knot-resolver/ahocorasick.so \
		lib/knot-resolver/kres_modules/bogus_log.so \
		lib/knot-resolver/kres_modules/dnstap.so \
		lib/knot-resolver/kres_modules/edns_keepalive.so \
		lib/knot-resolver/kres_modules/hints.so \
		lib/knot-resolver/kres_modules/lib/knot-resolver/kres_modules/nsid.so \
		lib/knot-resolver/kres_modules/refuse_nord.so \
		lib/knot-resolver/kres_modules/stats.so

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
