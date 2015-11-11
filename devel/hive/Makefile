# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hive
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/stable \
		LOCAL/demon/:maven \
		http://people.freebsd.org/~demon/:maven
DISTFILES=	apache-${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Framework for data warehousing on top of Hadoop

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3 \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yarn:${PORTSDIR}/devel/hadoop2

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.7+
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}-src

HIVE_USER=	hive
HIVE_GROUP=	hive
HIVE_LOGDIR=	/var/log/hive
HIVE_RUNDIR=	/var/run/hive
PLIST_SUB=	HIVE_VER=${PORTVERSION} \
		HIVE_USER=${HIVE_USER} \
		HIVE_GROUP=${HIVE_GROUP} \
		HIVE_RUNDIR=${HIVE_RUNDIR} \
		HIVE_LOGDIR=${HIVE_LOGDIR}
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		HIVE_USER=${HIVE_USER} \
		HIVE_GROUP=${HIVE_GROUP} \
		HIVE_RUNDIR=${HIVE_RUNDIR} \
		HIVE_LOGDIR=${HIVE_LOGDIR}
USERS=		${HIVE_USER}
GROUPS=		${HIVE_GROUP}
USE_RC_SUBR=	hiveserver2 metastore

HIVE_DIST=	${WRKSRC}/packaging/target/apache-hive-${PORTVERSION}-bin/apache-hive-${PORTVERSION}-bin

post-patch:
		${REINPLACE_CMD} -e s#%%PREFIX%%#${PREFIX}# -e s#%%LOCALBASE%%#${LOCALBASE}# ${WRKSRC}/conf/hive-env.sh.template

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean install -Phadoop-2,dist -DskipTests

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/hive
	cd ${HIVE_DIST} && ${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX}/hive
	cd ${HIVE_DIST} && ${COPYTREE_SHARE} "conf examples hcatalog lib scripts" ${STAGEDIR}${PREFIX}/hive
	${MKDIR} ${STAGEDIR}${HIVE_LOGDIR}
	${MKDIR} ${STAGEDIR}${HIVE_RUNDIR}

.include <bsd.port.mk>
