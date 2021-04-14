# Created by: Leo Vandewoestijne <freebsd@dns.company>

PORTNAME=	knot-resolver
DISTVERSION=	5.3.0
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/ \
		https://dns.company/downloads/knot-resolver/

MAINTAINER=	freebsd@dns.company
COMMENT=	Caching full resolver implementation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake \
		flake8:devel/py-flake8@${PY_FLAVOR} \
		lua51-cqueues>=20200726_1:devel/lua-cqueues@lua51 \
		luacheck:devel/lua-luacheck

LIB_DEPENDS=	libdnssec.so:dns/knot3-lib \
		libgnutls.so:security/gnutls \
		libknot.so:dns/knot3-lib \
		liblmdb.so:databases/lmdb \
		libluajit-5.1.so:lang/luajit-openresty \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv \
		libzscanner.so:dns/knot3-lib

RUN_DEPENDS=	lua51-cqueues>=20200726_1:devel/lua-cqueues@lua51

USES=		compiler:c11 libedit libtool meson ncurses ninja pkgconfig \
		python:3.5+,build shebangfix tar:xz

USE_CXXSTD=	c++11

USE_RC_SUBR=	krescachegc kresd

SHEBANG_FILES=	scripts/bench.sh \
		scripts/build-in-obs.sh \
		scripts/coverage_c_combine.sh \
		scripts/coverage_env.sh \
		scripts/gen-cdefs.sh \
		scripts/get-date.sh \
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

MESON_ARGS=	--buildtype=release \
		--default-library=static \
		--libdir=${PREFIX}/lib \
		--pkg-config-path=${PREFIX}/libdata/pkgconfig \
		--prefix=${LOCALBASE} \
		-Dclient=enabled \
		-Duser=${USERS} \
		-Dgroup=${GROUPS} \
		-Dinstall_kresd_conf=enabled \
		-Dkeyfile_default=${ETCDIR}/root.keys \
		-Droot_hints=${ETCDIR}/root.hints \
		-Duser=${USERS} \
		-Dutils=enabled

LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	knot-1.* knot1-[0-6].*

SUB_FILES=	pkg-message

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR}

USERS=		kresd
GROUPS=		kresd
RUNDIR=		/var/run/kresd

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR}

OPTIONS_DEFINE=		DOCS EXAMPLES DNSTAP ROOTKEYS TRUSTANCHOR TEST TESTUNIT TESTCONF TESTEXTRA
OPTIONS_DEFAULT=	DOCS EXAMPLES        ROOTKEYS TRUSTANCHOR TEST TESTUNIT

DNSTAP_DESC=		dnstap support
ROOTKEYS_DESC=		install root.keys
TESTCONF_DESC=		Do config tests
TESTEXTRA_DESC=		Do extra tests
TESTUNIT_DESC=		Do unit tests
TEST_DESC=		Do tests
TRUSTANCHOR_DESC=	Trust anchor bootstrapping, management and stats

DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c \
			libprotobuf.so:devel/protobuf
DNSTAP_MESON_ON=	-Ddnstap=enabled
DNSTAP_MESON_OFF=	-Ddnstap=disabled
DNSTAP_PLIST_FILES=	lib/knot-resolver/kres_modules/dnstap.so

ROOTKEYS_MESON_ON=	-Dinstall_root_keys=enabled
ROOTKEYS_MESON_OFF=	-Dinstall_root_keys=disabled
ROOTKEYS_PLIST_FILES=	${ETCDIR}/root.keys

TESTCONF_BROKEN=	missing luajit basexx package
TESTCONF_MESON_ON=	-Dconfig_tests=enabled
TESTCONF_MESON_OFF=	-Dconfig_tests=disabled

TESTEXTRA_BROKEN=		CMake Error: The source directory misses CMakeLists.txt
TESTEXTRA_BUILD_DEPENDS=	git:devel/git
TESTEXTRA_USES=			cmake python:3
TESTEXTRA_MESON_ON=		-Dextra_tests=enabled -Dsendmmsg=disabled
TESTEXTRA_MESON_OFF=		-Dextra_tests=disabled

TESTUNIT_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka
TESTUNIT_MESON_ON=	-Dunit_tests=enabled
TESTUNIT_MESON_OFF=	-Dunit_tests=disabled

TRUSTANCHOR_MESON_ON=	-Dmanaged_ta=enabled
TRUSTANCHOR_MESON_OFF=	-Dmanaged_ta=disabled

PORTDOCS=	AUTHORS COPYING CodingStyle NEWS README.md
PORTEXAMPLES=	config.cluster config.docker config.internal config.isp \
		config.personal config.privacy config.splitview

STRIP_TARGETS=	sbin/kres-cache-gc \
		sbin/kresc \
		sbin/kresd \
		lib/knot-resolver/ahocorasick.so \
		lib/knot-resolver/kres_modules/bogus_log.so \
		lib/knot-resolver/kres_modules/dnstap.so \
		lib/knot-resolver/kres_modules/edns_keepalive.so \
		lib/knot-resolver/kres_modules/hints.so \
		lib/knot-resolver/kres_modules/lib/knot-resolver/kres_modules/nsid.so \
		lib/knot-resolver/kres_modules/refuse_nord.so \
		lib/knot-resolver/kres_modules/stats.so

pre-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}

pre-install-TEST-on: do-test

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/kresd.conf ${STAGEDIR}${ETCDIR}/kresd.conf.sample
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.for STRIP_TGT in ${STRIP_TARGETS}
	if [ -f ${STAGEDIR}${PREFIX}/${STRIP_TGT} ]; then \
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/${STRIP_TGT}; \
	fi
.endfor

.include <bsd.port.mk>
