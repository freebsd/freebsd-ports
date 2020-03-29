# $FreeBSD$

PORTNAME=	foundationdb-devel
DISTVERSION=	7.0.0.a.20190823
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Distributed, transactional key-value store

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libeio.so:devel/libeio

USES=		compiler:c++17-lang cmake mono:build python:build shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	wolfspider
GH_PROJECT=	foundationdb
GH_TAGNAME=	bc56b13

USE_RC_SUBR=	foundationdb

SHEBANG_FILES=	build/csprojtom4.py build/link-wrapper.sh build/vcxprojtom4.py \
		bindings/c/generate_asm.py

CXXFLAGS+=	-Wno-implicit-int-float-conversion

USERS=		foundationdb
GROUPS=		foundationdb
DBDIR?=		/var/db/foundationdb
LOGDIR?=	/var/log/foundationdb

SUB_FDB=	DB_USER=${USERS} \
		DB_GROUP=${GROUPS} \
		DB_DIR=${DBDIR} \
		LOG_DIR=${LOGDIR}
SUB_FILES+=	foundationdb.conf
SUB_LIST+=	${SUB_FDB}
PLIST_SUB+=	${SUB_FDB}

do-install:
	# commands on first line, dev tools on next two
.for f in fdbbackup fdbcli fdbmonitor fdbserver \
	    actor_flamegraph fdb_c_performance_test fdb_c_ryw_benchmark \
	    fdb_c_txn_size_test fdb_flow_tester mako
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	# confirm with upstream if these are actually needed
.for s in backup_agent dr_agent fdbr fdbrestore
	${RLN} ${STAGEDIR}${PREFIX}/bin/fdbbackup ${STAGEDIR}${PREFIX}/bin/${s}
.endfor
	# exposed libraries - confirm with upstream
.for l in libfdb_c.so libfdb_flow.a libfdb_sqlite.a libfdbclient.a libfdbrpc.a libflow.a libthirdparty.a
	${STRIP_CMD} ${WRKDIR}/.build/lib/${l}
	${INSTALL_DATA} ${WRKDIR}/.build/lib/${l} ${STAGEDIR}/${PREFIX}/lib/
.endfor
	# exposed headers - confirm with upstream
	${MKDIR} ${STAGEDIR}${PREFIX}/include/foundationdb
	${INSTALL_DATA} ${WRKSRC}/bindings/c/foundationdb/fdb_c.h \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_DATA} ${WRKSRC}/fdbclient/vexillographer/fdb.options \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	${INSTALL_DATA} ${WRKDIR}/.build/bindings/c/foundationdb/fdb_c_options.g.h \
	    ${STAGEDIR}/${PREFIX}/include/foundationdb/
	# runtime related
	${MKDIR} ${STAGEDIR}${DBDIR} \
	    ${STAGEDIR}${LOGDIR} \
	    ${STAGEDIR}${PREFIX}/etc/foundationdb
	${INSTALL_DATA} ${WRKDIR}/foundationdb.conf \
	    ${STAGEDIR}${PREFIX}/etc/foundationdb/foundationdb.conf.sample

.include <bsd.port.mk>
