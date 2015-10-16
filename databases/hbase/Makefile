# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hbase
PORTVERSION=	0.98.9
CATEGORIES=	databases java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		LOCAL/demon/:maven \
		http://people.freebsd.org/~demon/:maven
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} FreeBSD-hbase-${PORTVERSION}-maven-repository.tar.gz:maven
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Hadoop database, a distributed, scalable, big data store

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake \
		${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yarn:${PORTSDIR}/devel/hadoop2

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.7+

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

HBASE_LOGDIR=	/var/log/${PORTNAME}
HBASE_RUNDIR=	/var/run/${PORTNAME}

HBASE_DIST=	${WRKSRC}/hbase-assembly/target/${PORTNAME}-${PORTVERSION}

HBASE_USER=	hbase
HBASE_GROUP=	hbase
USERS=		${HBASE_USER}
GROUPS=		${HBASE_GROUP}

SUB_FILES=	hbase-env-dist.sh pkg-message
USE_RC_SUBR=    hbase_master hbase_regionserver
SUB_LIST=	HBASE_USER="${HBASE_USER}" \
		JAVA_HOME="${JAVA_HOME}" \
		HBASE_LOG_DIR="${HBASE_LOGDIR}" \
		HBASE_PID_DIR="${HBASE_RUNDIR}"
PLIST_SUB=	HBASE_USER=${HBASE_USER} \
		HBASE_GROUP=${HBASE_GROUP} \
		HBASE_LOGDIR=${HBASE_LOGDIR} \
		HBASE_RUNDIR=${HBASE_RUNDIR} \
		PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:M1.8.*}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-PoolMap.java \
		${FILESDIR}/extra-patch-pom.xml
.endif

post-patch:
	${REINPLACE_CMD} -e "s#%%ETCDIR%%#${ETCDIR}#" ${WRKSRC}/conf/hbase-env.sh ${WRKSRC}/bin/hbase
	${RM} ${WRKSRC}/conf/hbase-env.sh.bak ${WRKSRC}/conf/hbase-env.sh.orig

do-build:
	cd ${WRKSRC} && bash dev-support/generate-hadoopX-poms.sh ${PORTVERSION}-RELEASE ${PORTVERSION}-hadoop2-RELEASE
	cd ${WRKSRC} && ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean install -Prelease,native -DskipTests
	cd ${WRKSRC} && ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline install -DskipTests site assembly:single -Prelease,native

post-build:
	cd ${WRKSRC}/hbase-assembly/target && ${TAR} xf ${PORTNAME}-${PORTVERSION}-bin.tar.gz
	${RM} ${HBASE_DIST}/conf/*.cmd

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/hbase/bin
	cd ${HBASE_DIST}/bin && ${INSTALL_SCRIPT} *.sh hbase hirb.rb ${STAGEDIR}${PREFIX}/hbase/bin/
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${HBASE_DIST} && ${COPYTREE_SHARE} conf ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/hbase-env-dist.sh ${STAGEDIR}${ETCDIR}/
	cd ${HBASE_DIST}/docs && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DOCSDIR}/
	cd ${HBASE_DIST} && ${COPYTREE_SHARE} hbase-webapps ${STAGEDIR}${PREFIX}/hbase/
	cd ${HBASE_DIST} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/hbase/ "! -name hadoop-*.jar"
	${MKDIR} ${STAGEDIR}${HBASE_LOGDIR}
	${MKDIR} ${STAGEDIR}${HBASE_RUNDIR}

.include <bsd.port.post.mk>
