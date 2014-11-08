# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leofs
PORTVERSION=	1.2.0
CATEGORIES=	databases

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Highly scalable, fault-tolerant distributed file system

LICENSE=	APACHE20

DISTFILES=	leofs-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	leofs-${PORTVERSION}.tar.gz

DIST_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	${LOCALBASE}/lib/erlang16/bin/erlc:${PORTSDIR}/lang/erlang-runtime16 \
		${LOCALBASE}/bin/cmake:${PORTSDIR}/devel/cmake \
		${LOCALBASE}/lib/libcheck.a:${PORTSDIR}/devel/libcheck

USE_GITHUB=	yes
GH_ACCOUNT=	leo-project
GH_PROJECT=	leofs
GH_TAGNAME=	2f6d896
GH_COMMIT=	2f6d896

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

USES=		gmake pkgconfig dos2unix
USE_RC_SUBR=	${PORTNAME}

DOS2UNIX_FILES=	deps/leo_*/snmp/snmpa_*/leo_*_snmp.config

ALL_TARGET=	release
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang16/bin:${PATH}

LEOFS_DEPS=	\
	leo-project/leo_gateway=${PORTVERSION}?2249fc4:leo_gateway \
	leo-project/leo_manager=${PORTVERSION}?3f6c0f6:leo_manager \
	leo-project/leo_storage=${PORTVERSION}?34f304d:leo_storage \
	DeadZen/goldrush=0.1.6?71e6321:goldrush \
	basho/cuttlefish=origin/develop?c2c7679:cuttlefish \
	basho/eleveldb=1.4.10?a84b18c:eleveldb \
	basho/lager=2.0.3?b6b6ceb:lager \
	basho/leveldb=1.4.10?be8f1f4:leveldb \
	boundary/bear=0.8.1?5f99806:bear \
	boundary/folsom=4824aec?4824aec:folsom \
	davisp/jiffy=0.11.3?99867af:jiffy \
	eproxus/meck=0.8.2?dde7590:meck \
	extend/cowlib=1.0.0?d544a49:cowlib \
	extend/ranch=0.8.4?4f70a16:ranch \
	jcomellas/getopt=v0.4.3?659a28f:getopt \
	leo-project/bitcask=1.7.0?97d9345:bitcask \
	leo-project/elarm=238e4bb?238e4bb:elarm \
	leo-project/erlang-lz4=0.2.2?80a5777:lz4 \
	leo-project/erpcgen=0.2.3?b35d6b8:erpcgen \
	leo-project/leo_backend_db=1.1.3?d7e8979:leo_backend_db \
	leo-project/leo_cache=0.6.0?39c8210:leo_cache \
	leo-project/leo_commons=1.1.0?c1e6825:leo_commons \
	leo-project/leo_dcerl=0.2.11?929fd59:leo_dcerl \
	leo-project/leo_logger=1.1.3?a05cce4:leo_logger \
	leo-project/leo_mcerl=0.4.1?addcda0:leo_mcerl \
	leo-project/leo_mq=1.2.0?11571f0:leo_mq \
	leo-project/leo_object_storage=1.1.8?0d44205:leo_object_storage \
	leo-project/leo_ordning_reda=0.10.9?eb168f0:leo_ordning_reda \
	leo-project/leo_pod=0.6.2?cfd8557:leo_pod \
	leo-project/leo_redundant_manager=1.9.1?9c3bbe7:leo_redundant_manager \
	leo-project/leo_rpc=0.8.10?5f55064:leo_rpc \
	leo-project/leo_s3_libs=1.1.4?8b159b0:leo_s3_libs \
	leo-project/leo_statistics=1.0.7?4bdb570:leo_statistics \
	leo-project/libcutil=0.4.3?36b02d9:libcutil \
	leo-project/leo_watchdog=0.4.1?4d6db9b:leo_watchdog \
	leo-project/nfs_rpc_server=0.2.2?d63c5ba:nfs_rpc_server \
	leo-project/savanna_agent=0.4.4?850143a:savanna_agent \
	leo-project/savanna_commons=0.8.6?bbcc77f:savanna_commons \
	ninenines/cowboy=1.0.0?021f4f6:cowboy \
	manopapad/proper=7d535ac?7d535ac:proper \
	seancribbs/neotoma=1.7.2?760928e:neotoma \

.for dep in ${LEOFS_DEPS}
.for account in ${dep:C,/.*$,,}
.for project in ${dep:C,^[^/]+/([^=]+)=.*$,\1,}
.for tagname in ${dep:C,^[^=]+=([^\?]+)\?.*$,\1,}
.for commit in ${dep:C,^[^\?]+\?([^:]+):.*$,\1,}
.for label in ${dep:C,^.*:,,}
MASTER_SITES+=	https://codeload.github.com/${account}/${project}/legacy.tar.gz/${commit}?dummy=/:${label}
DISTFILES+=	${project}-${tagname}.tar.gz:${label}
.endfor
.endfor
.endfor
.endfor
.endfor
.endfor

post-extract:
.for dep in ${LEOFS_DEPS}
.for account in ${dep:C,/.*$,,}
.for project in ${dep:C,^[^/]+/([^=]+)=.*$,\1,}
.for tagname in ${dep:C,^[^=]+=([^\?]+)\?.*$,\1,}
.for commit in ${dep:C,^[^\?]+\?([^:]+):.*$,\1,}
.for label in ${dep:C,^.*:,,}
	@${MKDIR} ${WRKSRC}/deps/${label}
	@${TAR} -C ${WRKSRC}/deps/${label} --strip-components 1 \
		-xzf ${DISTDIR}/${DIST_SUBDIR}/${project}-${tagname}.tar.gz
	@if [ -f "${WRKSRC}/deps/${label}/src/${label}.app.src" ]; then \
	    ${REINPLACE_CMD} -e "s|{vsn, *git}|{vsn, \"${tagname}\"}|" \
		"${WRKSRC}/deps/${label}/src/${label}.app.src"; \
	fi
.endfor
.endfor
.endfor
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
		${WRKSRC}/deps/leo_gateway/priv/leo_gateway.conf \
		${WRKSRC}/deps/leo_gateway/priv/leo_gateway.schema \
		${WRKSRC}/deps/leo_gateway/snmp/snmpa_gateway_0/leo_gateway_snmp.config \
		${WRKSRC}/deps/leo_manager/priv/leo_manager_0.conf \
		${WRKSRC}/deps/leo_manager/priv/leo_manager_0.schema \
		${WRKSRC}/deps/leo_manager/priv/leo_manager_1.conf \
		${WRKSRC}/deps/leo_manager/priv/leo_manager_1.schema \
		${WRKSRC}/deps/leo_manager/snmp/snmpa_manager_0/leo_manager_snmp.config \
		${WRKSRC}/deps/leo_manager/snmp/snmpa_manager_1/leo_manager_snmp.config \
		${WRKSRC}/deps/leo_storage/priv/leo_storage.conf \
		${WRKSRC}/deps/leo_storage/priv/leo_storage.schema \
		${WRKSRC}/deps/leo_storage/snmp/snmpa_storage_0/leo_storage_snmp.config

pre-build:
	(cd ${WRKSRC}/deps/erpcgen && ${MAKE_ENV} ${MAKE})
	(cd ${WRKSRC} && ${MAKE_ENV} ./deps/erpcgen/priv/erpcgen \
		-a [svc_callback,xdr,hrl] deps/leo_gateway/src/leo_nfs_proto3.x)
	(cd ${WRKSRC} && ${MAKE_ENV} ./deps/erpcgen/priv/erpcgen \
		-a [svc_callback,xdr,hrl] deps/leo_gateway/src/leo_nfs_mount3.x)
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

.include <bsd.port.mk>
