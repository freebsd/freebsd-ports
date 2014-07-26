# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leofs
PORTVERSION=	1.0.2
PORTREVISION=	1
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
GH_TAGNAME=	26c99d1
GH_COMMIT=	26c99d1

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
	leo-project/leo_gateway=${PORTVERSION}?498fa83:leo_gateway \
	leo-project/leo_manager=${PORTVERSION}?ec208bc:leo_manager \
	leo-project/leo_storage=${PORTVERSION}?b1e6112:leo_storage \
	basho/bitcask=1.6.7?807b473:bitcask \
	basho/eleveldb=1.4.7?98a465d:eleveldb \
	basho/leveldb=1.4.7?b1678e6:leveldb \
	boundary/bear=0.8.1?5f99806:bear \
	boundary/folsom=0.8.1?015c646:folsom \
	davisp/jiffy=0.8.5?d16a4fd:jiffy \
	eproxus/meck=0.6.2?2447206:meck \
	extend/cowboy=0.8.6?9eaee45:cowboy \
	extend/ranch=0.8.4?4f70a16:ranch \
	leo-project/erlang-lz4=0.2.1?74a475a:lz4 \
	leo-project/leo_backend_db=1.0.3?502a3b5:leo_backend_db \
	leo-project/leo_cache=0.4.20?501d8cd:leo_cache \
	leo-project/leo_commons=1.0.1?90b1b96:leo_commons \
	leo-project/leo_dcerl=0.2.8?2ca267d:leo_dcerl \
	leo-project/leo_logger=1.0.2?7b90fad:leo_logger \
	leo-project/leo_mcerl=0.2.10?1fb1ac8:leo_mcerl \
	leo-project/leo_mq=1.0.3?f425615:leo_mq \
	leo-project/leo_object_storage=1.0.4?54cf0f7:leo_object_storage \
	leo-project/leo_ordning_reda=0.10.3?be722bb:leo_ordning_reda \
	leo-project/leo_pod=0.6.0?9a7de8b:leo_pod \
	leo-project/leo_redundant_manager=1.8.1?abb473a:leo_redundant_manager \
	leo-project/leo_rpc=0.8.3?073ef14:leo_rpc \
	leo-project/leo_s3_libs=1.0.1?4ada19b:leo_s3_libs \
	leo-project/leo_statistics=1.0.2?7ba5f23:leo_statistics \
	leo-project/libcutil=0.4.3?36b02d9:libcutil \
	leo-project/savanna_agent=0.2.2?96f3420:savanna_agent \
	leo-project/savanna_commons=0.6.3?b4e7fea:savanna_commons \
	manopapad/proper=7d535ac?7d535ac:proper

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
	    ${REINPLACE_CMD} -e "s/{vsn, *git}/{vsn, \"${tagname}\"}/" \
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
.for f in ${LEOFS_SBIN_FILES}
	${INSTALL_SCRIPT} ${WRKDIR}/sbin-${f} ${STAGEDIR}${PREFIX}/sbin/${f}
.endfor

.include <bsd.port.mk>
