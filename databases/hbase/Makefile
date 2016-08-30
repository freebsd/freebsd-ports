# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hbase
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION} \
		http://kev009.com/freebsd/:maven
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Hadoop database, a distributed, scalable, big data store

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake \
		${LOCALBASE}/share/java/maven3/bin/mvn:devel/maven3
RUN_DEPENDS=	bash:shells/bash \
		yarn:devel/hadoop2

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.7+
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} MAVEN_OPTS="-XX:MaxPermSize=256m"

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
JDK18_PROFILE=	,build-with-jdk8
JDK18_SOURCE=	-DcompileSource=1.8
.endif

post-patch:
	${REINPLACE_CMD} -e "s#%%ETCDIR%%#${ETCDIR}#" ${WRKSRC}/conf/hbase-env.sh ${WRKSRC}/bin/hbase
	${RM} ${WRKSRC}/conf/hbase-env.sh.bak ${WRKSRC}/conf/hbase-env.sh.orig

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean install -Prelease,native${JDK18_PROFILE} -DskipTests ${JDK18_SOURCE}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline install -DskipTests site assembly:single -Prelease,native${JDK18_PROFILE} ${JDK18_SOURCE}

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
	${CHMOD} 644 ${STAGEDIR}${PREFIX}/hbase/lib/native/libmlockall_agent.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/hbase/lib/native/libmlockall_agent.so

.include <bsd.port.post.mk>
