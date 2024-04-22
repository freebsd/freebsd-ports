PORTNAME=	foundationdb
DISTVERSION=	7.1.29
CATEGORIES=	databases

# PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/pull/

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Distributed, transactional key-value store
WWW=		https://www.foundationdb.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	invalid asm rdtsc
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything else

BUILD_DEPENDS=	${LOCALBASE}/include/msgpack.hpp:devel/msgpack-cxx \
		${LOCALBASE}/include/toml.hpp:devel/toml11 \
		bash:shells/bash \
		git:devel/git
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libeio.so:devel/libeio

USES=		cmake compiler:c++20-lang mono:build python:build shebangfix \
		ssl
USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	foundationdb
USE_LDCONFIG=	yes
USE_RC_SUBR=	foundationdb

SHEBANG_FILES=	bindings/c/generate_asm.py

CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLLIB}
CMAKE_OFF=	DISABLE_TLS USE_DTRACE USE_JEMALLOC WITH_CONTRIB WITH_FLOWBENCH

MAKE_ENV=	MONO_REGISTRY_PATH=/tmp/registry

SUB_FILES=	foundationdb.conf
SUB_LIST=	${SUB_FDB}

USERS=		foundationdb
GROUPS=		foundationdb

PLIST_SUB=	${SUB_FDB}

FOUNDATIONDB_DBDIR?=	/var/db/foundationdb
FOUNDATIONDB_ETCDIR?=	${PREFIX}/etc/foundationdb
FOUNDATIONDB_GROUP?=	foundationdb
FOUNDATIONDB_LOGDIR?=	/var/log/foundationdb
FOUNDATIONDB_USER?=	foundationdb

SUB_FDB=	FOUNDATIONDB_DBDIR=${FOUNDATIONDB_DBDIR} \
		FOUNDATIONDB_ETCDIR=${FOUNDATIONDB_ETCDIR} \
		FOUNDATIONDB_GROUP=${FOUNDATIONDB_GROUP} \
		FOUNDATIONDB_LOGDIR=${FOUNDATIONDB_LOGDIR} \
		FOUNDATIONDB_USER=${FOUNDATIONDB_USER}

post-patch:
		${REINPLACE_CMD} 's/OPENSSL_USE_STATIC_LIBS TRUE/OPENSSL_USE_STATIC_LIBS FALSE/' \
		${WRKSRC}/cmake/FDBComponents.cmake
		${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/bindings/c/test/unit/third_party/CMakeLists.txt

do-install:
# commands on first line, dev tools on next two
.for f in fdbbackup fdbcli fdbmonitor fdbserver actor_flamegraph fdb_flow_tester \
	fdbconvert fdbdecode tutorial
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for s in backup_agent dr_agent fastrestore_agent fdbr fdbrestore
	${RLN} ${STAGEDIR}${PREFIX}/bin/fdbbackup ${STAGEDIR}${PREFIX}/bin/${s}
.endfor
# exposed libraries - confirm with upstream
.for l in libfdb_c.so libfdb_flow.a libfdb_sqlite.a libfdbclient.a libfdbrpc.a \
	libflow.a
	${STRIP_CMD} ${WRKDIR}/.build/lib/${l}
	${INSTALL_DATA} ${WRKDIR}/.build/lib/${l} ${STAGEDIR}/${PREFIX}/lib/
.endfor
# exposed headers - confirm with upstream
	${MKDIR} ${STAGEDIR}${PREFIX}/include/foundationdb
	${INSTALL_DATA} ${WRKSRC}/bindings/c/foundationdb/fdb_c.h \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_DATA} ${WRKSRC}/bindings/c/foundationdb/fdb_c_types.h \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_DATA} ${WRKSRC}/fdbclient/vexillographer/fdb.options \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_DATA} ${WRKDIR}/.build/bindings/c/foundationdb/fdb_c_options.g.h \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
# runtime related
	${MKDIR} ${STAGEDIR}${FOUNDATIONDB_ETCDIR}
	${MKDIR} ${STAGEDIR}${FOUNDATIONDB_DBDIR}
	${MKDIR} ${STAGEDIR}${FOUNDATIONDB_LOGDIR}
	${INSTALL_DATA} ${WRKDIR}/foundationdb.conf \
	    ${STAGEDIR}${FOUNDATIONDB_ETCDIR}/foundationdb.conf.sample

.include <bsd.port.mk>
