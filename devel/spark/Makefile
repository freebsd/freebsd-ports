# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spark
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		LOCAL/demon/:maven \
		http://people.freebsd.org/~demon/:maven
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Fast big data processing engine

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yarn:${PORTSDIR}/devel/hadoop2

USES=		python:2
USE_JAVA=	yes
JAVA_VERSION=	1.7+
MAKE_ENV+=	MAVEN_OPTS="-Xmx2g -XX:MaxPermSize=512M -XX:ReservedCodeCacheSize=512m"
NO_ARCH=	YES

USERS=		spark
GROUPS=		spark

USE_RC_SUBR=	spark_master spark_worker
PLIST_SUB+=	SPARK_USER=spark SPARK_GROUP=spark VER=${PORTVERSION}
SUB_LIST+=	SPARK_USER=spark SPARK_GROUP=spark

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn --offline -Dmaven.repo.local=${WRKDIR}/m2 clean package -Dhadoop.version=2.4.1 -Pyarn -Phadoop-2.4 -DskipTests

post-build:
	${RM} ${WRKSRC}/bin/*.cmd ${WRKSRC}/sbin/spark-daemon.sh.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/examples ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/sbin ${STAGEDIR}${DATADIR}/conf
	${ECHO_CMD} "Spark $PORTVERSION built for Hadoop 2.4.1" > ${STAGEDIR}${DATADIR}/RELEASE
	${INSTALL_DATA} ${WRKSRC}/assembly/target/scala*/*assembly*hadoop*.jar ${STAGEDIR}${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/examples/target/scala*/spark-examples*.jar ${STAGEDIR}${DATADIR}/lib/
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}/examples/
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/sbin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} python ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/
	${MKDIR} ${STAGEDIR}/var/run/spark
	${MKDIR} ${STAGEDIR}/var/log/spark

.include <bsd.port.mk>
