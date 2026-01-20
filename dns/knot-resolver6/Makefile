PORTNAME=	knot-resolver
DISTVERSION=	6.1.0
CATEGORIES=	dns
MASTER_SITES=	https://knot-resolver.nic.cz/release/ \
		https://dns.company/downloads/knot-resolver/
PKGNAMESUFFIX?=	6

MAINTAINER=	freebsd@dns.company
COMMENT=	Caching full resolver implementation
WWW=		https://www.knot-resolver.cz/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		flake8:devel/py-flake8@${PY_FLAVOR} \
		${LUA_FLAVOR}-cqueues>=20200726_1:devel/lua-cqueues@${LUA_FLAVOR} \
		luacheck:devel/lua-luacheck
LIB_DEPENDS=	libdnssec.so:dns/knot3 \
		libgnutls.so:security/gnutls \
		libknot.so:dns/knot3 \
		liblmdb.so:databases/lmdb \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv \
		libzscanner.so:dns/knot3
RUN_DEPENDS=	${LUA_FLAVOR}-cqueues>=20200726_1:devel/lua-cqueues@${LUA_FLAVOR}

USES=		cmake:indirect compiler:c11 lua:build,run luajit meson ncurses \
		ninja pkgconfig python:build tar:xz
USE_CXXSTD=	c++11
USE_RC_SUBR=	krescachegc kresd

CMAKE_ARGS+=	-DCLANG_TIDY=${LOCALBASE}/bin/clang-tidy${COMPILER_VERSION:C/.$//} \
		-DRUN_CLANG_TIDY=${LOCALBASE}/llvm${COMPILER_VERSION:C/.$//}/bin/run-clang-tidy

MESON_ARGS=	--buildtype=release \
		--default-library=static \
		--libdir=${PREFIX}/lib \
		--pkg-config-path=${PREFIX}/libdata/pkgconfig \
		--prefix=${LOCALBASE} \
		--strip \
		-Dgroup=${GROUPS} \
		-Dinstall_kresd_conf=enabled \
		-Dkeyfile_default=${ETCDIR}/root.keys \
		-Dmalloc=auto \
		-Droot_hints=${ETCDIR}/root.hints \
		-Duser=${USERS} \
		-Dutils=enabled

CONFLICTS=	knot-resolver-[0-5].*

SUB_FILES=	pkg-message

KRESD_USER=	kresd
KRESD_GROUP=	kresd
KRESD_RUNDIR=	/var/run/kresd

SUB_LIST=	GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR} \
		USERS=${USERS}

USERS=		${KRESD_USER}
GROUPS=		${KRESD_GROUP}
RUNDIR=		${KRESD_RUNDIR}

PLIST_SUB=	GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR} \
		USERS=${USERS}

PORTDOCS=	AUTHORS COPYING CodingStyle NEWS README.md
PORTEXAMPLES=	config.cluster config.docker config.internal config.isp \
		config.personal config.privacy config.splitview

OPTIONS_DEFINE=		DOCS EXAMPLES DNSTAP TESTUNIT

DNSTAP_DESC=		dnstap support
TESTUNIT_DESC=		Build unit tests

DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c \
			libprotobuf.so:devel/protobuf
DNSTAP_MESON_ON=	-Ddnstap=enabled
DNSTAP_MESON_OFF=	-Ddnstap=disabled
DNSTAP_PLIST_FILES=	lib/knot-resolver/kres_modules/dnstap.so

TESTUNIT_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka
TESTUNIT_MESON_ON=	-Dunit_tests=enabled
TESTUNIT_MESON_OFF=	-Dunit_tests=disabled
TESTUNIT_LDFLAGS=	-pthread

post-install:
	${MKDIR} ${STAGEDIR}${RUNDIR}
	${MV} ${STAGEDIR}${ETCDIR}/kresd.conf ${STAGEDIR}${ETCDIR}/kresd.conf.sample
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
