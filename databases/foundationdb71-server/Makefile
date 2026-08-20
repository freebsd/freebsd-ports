PORTNAME?=	foundationdb
DISTVERSION=	7.1.67
CATEGORIES?=	databases
MASTER_SITES=	SF/boost/boost/${BOOST_VERSION}:boost
PKGNAMESUFFIX?=	${DISTVERSION:C/([0-9]+)\.([0-9]+).*/\1\2/}-${_COMPONENT}
DISTFILES=	boost_${BOOST_VERSION_UNDER}${EXTRACT_SUFX}:boost

MAINTAINER?=	drtr0jan@yandex.ru
COMMENT?=	FoundationDB is a large-scale distributed database
WWW=		https://www.foundationdb.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything else

BUILD_DEPENDS=	bash:shells/bash \
		msgpack-cxx>0:devel/msgpack-cxx \
		toml11>=4.0.0:devel/toml11
LIB_DEPENDS=	libeio.so:devel/libeio

USES=		cmake compiler:c++20-lang llvm mono:build python:build \
		shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	foundationdb
USE_LDCONFIG=	yes

.if !defined(_CLIENT_ONLY)
_SERVER_ONLY=	yes
_COMPONENT=	server
USE_RC_SUBR=	foundationdb
RUN_DEPENDS+=	fdbcli:databases/${PORTNAME}${DISTVERSION:C/([0-9]+)\.([0-9]+).*/\1\2/}-client
SUB_FILES+=	foundationdb.conf
.endif

SHEBANG_FILES=	bindings/c/generate_asm.py

# Bundle last supported Boost release
BOOST_VERSION=		1.78.0
BOOST_VERSION_UNDER=	${BOOST_VERSION:C/\./_/g}

CMAKE_ARGS=	-DBOOST_SOURCE_DIR=${WRKDIR}/boost_${BOOST_VERSION_UNDER} \
		-DOPENSSL_ROOT_DIR=${OPENSSLLIB}
CMAKE_OFF=	BUILD_DOCUMENTATION BUILD_GO_BINDING BUILD_JAVA_BINDING \
		BUILD_PYTHON_BINDING BUILD_RUBY_BINDING DISABLE_TLS \
		SSD_ROCKSDB_EXPERIMENTAL USE_DTRACE USE_JEMALLOC

MAKE_ENV=	MONO_REGISTRY_PATH=/tmp/registry

CONFLICTS+=	${PORTNAME}*-${_COMPONENT}*

SUB_LIST=	${SUB_FDB}

FOUNDATIONDB_USER?=	${PORTNAME}
FOUNDATIONDB_GROUP?=	${PORTNAME}
FOUNDATIONDB_DBDIR?=	/var/db/${PORTNAME}
FOUNDATIONDB_LOGDIR?=	/var/log/${PORTNAME}

.if ${FOUNDATIONDB_USER} == ${PORTNAME}
USERS=		${FOUNDATIONDB_USER}
.endif
.if ${FOUNDATIONDB_GROUP} == ${PORTNAME}
GROUPS=		${FOUNDATIONDB_GROUP}
.endif

PLIST=		${PKGDIR}/pkg-plist-${_COMPONENT}
PLIST_SUB=	${SUB_FDB}

SUB_FDB=	FOUNDATIONDB_USER=${FOUNDATIONDB_USER} \
		FOUNDATIONDB_GROUP=${FOUNDATIONDB_GROUP} \
		FOUNDATIONDB_DBDIR=${FOUNDATIONDB_DBDIR} \
		FOUNDATIONDB_LOGDIR=${FOUNDATIONDB_LOGDIR}

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/../boost_${BOOST_VERSION_UNDER}/boost/container_hash/hash.hpp
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.if defined(_SERVER_ONLY)
	${MKDIR} ${STAGEDIR}${FOUNDATIONDB_DBDIR}
	${MKDIR} ${STAGEDIR}${FOUNDATIONDB_LOGDIR}
	${INSTALL_DATA} ${WRKDIR}/foundationdb.conf ${STAGEDIR}${ETCDIR}/foundationdb.conf.sample
.  for f in fdbserver fdbmonitor
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/${f} ${STAGEDIR}${PREFIX}/sbin/
.  endfor
.endif # _SERVER_ONLY
.if defined(_CLIENT_ONLY)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/foundationdb
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/foundationdb/backup_agent
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/fdbcli ${STAGEDIR}${PREFIX}/bin/
.  for l in libfdb_c.so
	${INSTALL_LIB} ${WRKDIR}/.build/lib/${l} ${STAGEDIR}/${PREFIX}/lib/
.  endfor
.  for i in fdb_c.h fdb_c_internal.h fdb_c_types.h
	${INSTALL_DATA} ${WRKSRC}/bindings/c/foundationdb/${i} \
		${STAGEDIR}/${PREFIX}/include/foundationdb/
.  endfor
.  for i in fdb_c_options.g.h
	${INSTALL_DATA} ${WRKDIR}/.build/bindings/c/foundationdb/${i} \
		${STAGEDIR}/${PREFIX}/include/foundationdb/
.  endfor
	${INSTALL_DATA} ${WRKSRC}/fdbclient/vexillographer/fdb.options \
		${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/fdbbackup \
		${STAGEDIR}${PREFIX}/lib/foundationdb/backup_agent/backup_agent
.  for s in fdbbackup fdbrestore fdbdr dr_agent
	${RLN} ${STAGEDIR}${PREFIX}/lib/foundationdb/backup_agent/backup_agent \
		${STAGEDIR}${PREFIX}/bin/${s}
.  endfor
.endif # _CLIENT_ONLY

.include <bsd.port.post.mk>
