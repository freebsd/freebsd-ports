# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leofs
PORTVERSION=	1.3.4
CATEGORIES=	databases
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Highly scalable, fault-tolerant distributed file system

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/erlang18/bin/erlc:lang/erlang-runtime18 \
		${LOCALBASE}/bin/cmake:devel/cmake \
		${LOCALBASE}/lib/libcheck.a:devel/check

USE_GITHUB=	yes
GH_ACCOUNT=	leo-project

BROKEN_aarch64=		Does not compile: fatal error: lzo/lzo1x.h file not found
NOT_FOR_ARCHS=		powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	does not build: error Please implement AtomicPointer for this platform

LEOFS_USER=	leofs
LEOFS_GROUP=	leofs
USERS=		${LEOFS_USER}
GROUPS=		${LEOFS_GROUP}

LEOFS_ETCDIR=	${ETCDIR}
LEOFS_BASEDIR=	${PREFIX}/lib/${PORTNAME}
LEOFS_DBDIR=	/var/db/${PORTNAME}
LEOFS_LOGDIR=	/var/log/${PORTNAME}
LEOFS_RUNDIR=	/var/run/${PORTNAME}

LEOFS_SBIN_FILES= \
		leo_gateway \
		leo_manager \
		leo_manager_slave \
		leo_storage \
		leofs

PLIST_SUB+=	LEOFS_USER=${LEOFS_USER} \
		LEOFS_GROUP=${LEOFS_GROUP} \
		LEOFS_DBDIR=${LEOFS_DBDIR} \
		LEOFS_LOGDIR=${LEOFS_LOGDIR} \
		LEOFS_RUNDIR=${LEOFS_RUNDIR}

SUB_LIST+=	LEOFS_USER=${LEOFS_USER} \
		LEOFS_GROUP=${LEOFS_GROUP} \
		LEOFS_ETCDIR=${LEOFS_ETCDIR} \
		LEOFS_BASEDIR=${LEOFS_BASEDIR} \
		LEOFS_DBDIR=${LEOFS_DBDIR} \
		LEOFS_LOGDIR=${LEOFS_LOGDIR} \
		LEOFS_RUNDIR=${LEOFS_RUNDIR}

SUB_FILES+=	${LEOFS_SBIN_FILES:S/^/sbin-/}

USES=		dos2unix gmake pkgconfig ssl
USE_RC_SUBR=	${PORTNAME}

DOS2UNIX_FILES=	apps/leo_*/snmp/snmpa_*/leo_*_snmp.config

ALL_TARGET=	release
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang18/bin:${PATH}

LEOFS_DEPS=	\
	basho/bitcask=2.0.7:bitcask \
	basho/cuttlefish=2.0.11:cuttlefish \
	basho/eleveldb=2.0.33:eleveldb \
	basho/getopt=v0.8.2:getopt \
	basho/goldrush=0.1.9:goldrush \
	basho/lager=3.2.4:lager \
	basho/leveldb=2.0.33:leveldb \
	basho/neotoma=1.7.4:neotoma \
	davisp/jiffy=0.14.8:jiffy \
	eproxus/meck=0.8.4:meck \
	extend/ranch=1.0.0:ranch \
	ferd/erlpass=1.0.3:erlpass \
	ferd/recon=2.3.1:recon \
	leo-project/bear=0.8.2-for-leofs:bear \
	leo-project/cowboy=for-leofs-1.4:cowboy \
	leo-project/elarm=d9e8a6f:elarm \
	leo-project/erpcgen=0.2.5:erpcgen \
	leo-project/folsom=0.8.2-p1:folsom \
	leo-project/leo_backend_db=1.2.12:leo_backend_db \
	leo-project/leo_cache=0.8.3:leo_cache \
	leo-project/leo_commons=1.1.9:leo_commons \
	leo-project/leo_dcerl=0.4.6:leo_dcerl \
	leo-project/leo_logger=1.2.5:leo_logger \
	leo-project/leo_mcerl=0.6.4:leo_mcerl \
	leo-project/leo_mq=1.4.17:leo_mq \
	leo-project/leo_object_storage=1.3.6:leo_object_storage \
	leo-project/leo_ordning_reda=1.2.4:leo_ordning_reda \
	leo-project/leo_pod=0.6.8:leo_pod \
	leo-project/leo_redundant_manager=1.9.39:leo_redundant_manager \
	leo-project/leo_rpc=0.10.12:leo_rpc \
	leo-project/leo_s3_libs=1.2.12:leo_s3_libs \
	leo-project/leo_statistics=1.1.17:leo_statistics \
	leo-project/leo_tran=0.2.8:leo_tran \
	leo-project/leo_watchdog=0.12.7:leo_watchdog \
	leo-project/libcutil=0.4.4:libcutil \
	leo-project/nfs_rpc_server=0.2.5:nfs_rpc_server \
	leo-project/savanna_agent=0.4.20:savanna_agent \
	leo-project/savanna_commons=0.10.6:savanna_commons \
	manopapad/proper=f558989:proper \
	ninenines/cowlib=1.0.0:cowlib \
	smarkets/erlang-bcrypt=a63df34:bcrypt \

GH_TUPLE=	${LEOFS_DEPS:C,(.*)/(.*)=(.*):(.*),\1:\2:\3:\4/deps/\4,}

post-extract:
.for dep in ${LEOFS_DEPS}
.for tagname in ${dep:C,^[^=]+=([^\?]+)\?.*$,\1,}
.for label in ${dep:C,^.*:,,}
	@if [ -f "${WRKSRC}/deps/${label}/src/${label}.app.src" ]; then \
	    ${REINPLACE_CMD} -e "s|{vsn, *git}|{vsn, \"${tagname}\"}|" \
		"${WRKSRC}/deps/${label}/src/${label}.app.src"; \
	fi
.endfor
.endfor
.endfor
	@(cd ${WRKSRC}/deps/eleveldb/c_src && ${LN} -s ../../leveldb)
	@(cd ${WRKSRC}/deps/leo_mcerl/c_src && ${LN} -s ../../libcutil)
	@(cd ${WRKSRC}/deps/leo_dcerl/c_src && ${LN} -s ../../libcutil)

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%LEOFS_DBDIR%%|${LEOFS_DBDIR}|g; \
		s|%%LEOFS_LOGDIR%%|${LEOFS_LOGDIR}|g;' \
		${WRKSRC}/apps/leo_gateway/priv/leo_gateway.conf \
		${WRKSRC}/apps/leo_gateway/priv/leo_gateway.schema \
		${WRKSRC}/apps/leo_gateway/snmp/snmpa_gateway_0/leo_gateway_snmp.config \
		${WRKSRC}/apps/leo_manager/priv/leo_manager_0.conf \
		${WRKSRC}/apps/leo_manager/priv/leo_manager_0.schema \
		${WRKSRC}/apps/leo_manager/priv/leo_manager_1.conf \
		${WRKSRC}/apps/leo_manager/priv/leo_manager_1.schema \
		${WRKSRC}/apps/leo_manager/snmp/snmpa_manager_0/leo_manager_snmp.config \
		${WRKSRC}/apps/leo_manager/snmp/snmpa_manager_1/leo_manager_snmp.config \
		${WRKSRC}/apps/leo_storage/priv/leo_storage.conf \
		${WRKSRC}/apps/leo_storage/priv/leo_storage.schema \
		${WRKSRC}/apps/leo_storage/snmp/snmpa_storage_0/leo_storage_snmp.config

pre-build:
	(cd ${WRKSRC}/deps/erpcgen && ${MAKE_ENV} ${MAKE})
	(cd ${WRKSRC} && ${MAKE_ENV} ./deps/erpcgen/priv/erpcgen \
		-a [svc_callback,xdr,hrl] apps/leo_gateway/src/leo_nfs_proto3.x)
	(cd ${WRKSRC} && ${MAKE_ENV} ./deps/erpcgen/priv/erpcgen \
		-a [svc_callback,xdr,hrl] apps/leo_gateway/src/leo_nfs_mount3.x)
	(cd ${WRKSRC}/deps/nfs_rpc_server/src && \
		${MAKE_ENV} erl -noshell -pa ../../erpcgen/ebin \
		-eval 'erpcgen:file(pmap,    [xdrlib,clnt])' -s init stop)
	(cd ${WRKSRC}/deps/nfs_rpc_server/src && \
		${MAKE_ENV} erl -noshell -pa ../../erpcgen/ebin \
		-eval 'erpcgen:file(nfs_rpc, [xdrlib,clnt])' -s init stop)

FIND_ARGS=	"! -name *.bak ! -name *.orig"

do-install:
	${MKDIR} \
		${STAGEDIR}${LEOFS_BASEDIR}/bin \
		${STAGEDIR}${LEOFS_BASEDIR}/snmp \
		${STAGEDIR}${LEOFS_BASEDIR}/releases/1 \
		${STAGEDIR}${LEOFS_ETCDIR} \
		${STAGEDIR}${LEOFS_DBDIR} \
		${STAGEDIR}${LEOFS_LOGDIR} \
		${STAGEDIR}${LEOFS_RUNDIR}
	(cd ${WRKSRC}/package/leo_gateway && \
		${COPYTREE_BIN} erts-*/bin ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS} && \
		${COPYTREE_SHARE} etc ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS})

	(cd ${WRKSRC}/package/leo_manager_0 && \
		${COPYTREE_SHARE} etc ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_storage && \
		${COPYTREE_SHARE} etc ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${LEOFS_BASEDIR} ${FIND_ARGS})
	${INSTALL_DATA} ${WRKSRC}/package/leo_manager_1/etc/leo_manager.schema \
		${STAGEDIR}${LEOFS_BASEDIR}/etc/leo_manager_slave.schema
	${INSTALL_DATA} ${WRKSRC}/package/leo_manager_1/etc/leo_manager.conf \
		${STAGEDIR}${LEOFS_BASEDIR}/etc/leo_manager_slave.conf
	${INSTALL_SCRIPT} ${WRKSRC}/package/leo_gateway/bin/cuttlefish \
		${STAGEDIR}${LEOFS_BASEDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/package/leo_gateway/releases/start_erl.data \
		${STAGEDIR}${LEOFS_BASEDIR}/releases
	${INSTALL_DATA} ${WRKSRC}/package/leo_gateway/releases/1/start_clean.* \
		${STAGEDIR}${LEOFS_BASEDIR}/releases/1
	(cd ${WRKSRC}/package/leo_gateway/releases && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/releases/leo_gateway ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_manager_0/releases && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/releases/leo_manager ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_storage/releases && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/releases/leo_storage ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_gateway/snmp/snmpa_gateway_0 && \
		${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/snmp/snmpa_gateway ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_manager_0/snmp/snmpa_manager_0 && \
		${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/snmp/snmpa_manager ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_manager_1/snmp/snmpa_manager_1 && \
		${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/snmp/snmpa_manager_slave ${FIND_ARGS})
	(cd ${WRKSRC}/package/leo_storage/snmp/snmpa_storage_0 && \
		${COPYTREE_SHARE} . \
		${STAGEDIR}${LEOFS_BASEDIR}/snmp/snmpa_storage ${FIND_ARGS})
	${INSTALL_DATA} ${WRKSRC}/package/leo_gateway/etc/leo_gateway.conf \
		${STAGEDIR}${LEOFS_ETCDIR}/leo_gateway.conf.sample
	${INSTALL_DATA} ${WRKSRC}/package/leo_gateway/etc/server_cert.pem \
		${STAGEDIR}${LEOFS_ETCDIR}/server_cert.pem.sample
	${INSTALL_DATA} ${WRKSRC}/package/leo_gateway/etc/server_key.pem \
		${STAGEDIR}${LEOFS_ETCDIR}/server_key.pem.sample
	${INSTALL_DATA} ${WRKSRC}/package/leo_manager_0/etc/leo_manager.conf \
		${STAGEDIR}${LEOFS_ETCDIR}/leo_manager.conf.sample
	${INSTALL_DATA} ${WRKSRC}/package/leo_manager_1/etc/leo_manager.conf \
		${STAGEDIR}${LEOFS_ETCDIR}/leo_manager_slave.conf.sample
	${INSTALL_DATA} ${WRKSRC}/package/leo_storage/etc/leo_storage.conf \
		${STAGEDIR}${LEOFS_ETCDIR}/leo_storage.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/leofs-adm ${STAGEDIR}${PREFIX}/sbin/leofs-adm
.for f in ${LEOFS_SBIN_FILES}
	${INSTALL_SCRIPT} ${WRKDIR}/sbin-${f} ${STAGEDIR}${PREFIX}/sbin/${f}
.endfor
	cd ${STAGEDIR}${PREFIX} ;					\
	    ${FIND} ${LEOFS_BASEDIR:S/${PREFIX}\///}			\
		${LEOFS_LIBXDIR:S/${PREFIX}\///} -type f -o -type l	\
		| ${SORT} > ${WRKDIR}/PLIST.leofs
	cd ${STAGEDIR}${PREFIX} ; 					\
	    ${FIND} ${LEOFS_BASEDIR:S/${PREFIX}\///}			\
		${LEOFS_LIBXDIR:S/${PREFIX}\///} -type d -empty		\
		| ${SORT} -r | ${SED} -e 's/^/@dir /' 			\
		>> ${WRKDIR}/PLIST.leofs
	${ECHO_CMD} "r ${TMPPLIST}"			>  ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.leofs"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.leofs"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-leofs
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
