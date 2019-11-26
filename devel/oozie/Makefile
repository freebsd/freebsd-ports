# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oozie
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION} \
		LOCAL/demon/:maven \
		http://archive.apache.org/dist/tomcat/tomcat-6/v${TOMCAT_VERSION}/bin/:tomcat \
		http://extjs.com/deploy/:libext \
		http://central.maven.org/maven2/org/apache/hadoop/hadoop-client/${HADOOP_VERSION}/:hadoopclient
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven apache-tomcat-${TOMCAT_VERSION}.tar.gz:tomcat ext-2.2.zip:libext hadoop-client-${HADOOP_VERSION}.jar:hadoopclient
DIST_SUBDIR=	hadoop
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Workflow scheduler for Hadoop

BROKEN=		unfetchable

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:devel/maven3 \
		yarn:devel/hadoop2 \
		zip:archivers/zip
RUN_DEPENDS=	bash:shells/bash \
		yarn:devel/hadoop2

USES=		shebangfix
USE_JAVA=	yes
TOMCAT_VERSION=	6.0.43
HADOOP_VERSION=	2.7.2		# Matches devel/hadoop2
SHEBANG_FILES=	client/src/main/bin/oozie distro/src/main/bin/addtowar.sh distro/src/main/bin/oozied.sh distro/src/main/bin/oozie-setup.sh distro/src/main/bin/oozie-sys.sh tools/src/main/bin/ooziedb.sh core/src/main/conf/oozie-env.sh

OOZIE_USER=	oozie
OOZIE_RUNDIR=	/var/run/oozie
OOZIE_LOGDIR=	/var/log/oozie
USERS=		${OOZIE_USER}
GROUPS=		${OOZIE_USER}

USE_RC_SUBR=	oozied
SUB_FILES=	pkg-message
PLIST_SUB=	OOZIE_USER=${OOZIE_USER} \
		OOZIE_RUNDIR=${OOZIE_RUNDIR} \
		OOZIE_LOGDIR=${OOZIE_LOGDIR} \
		OOZIE_VERSION=${PORTVERSION} \
		HADOOP_VERSION=${HADOOP_VERSION}
SUB_LIST=	OOZIE_USER=${OOZIE_USER} \
		OOZIE_RUNDIR=${OOZIE_RUNDIR}

do-build:
	${MKDIR} ${WRKSRC}/distro/downloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/apache-tomcat-${TOMCAT_VERSION}.tar.gz ${WRKSRC}/distro/downloads/tomcat-${TOMCAT_VERSION}.tar.gz
	${REINPLACE_CMD} -e s#%%OOZIE_LOGDIR%%#${OOZIE_LOGDIR}# -e s#%%OOZIE_RUNDIR%%#${OOZIE_RUNDIR}# ${WRKSRC}/core/src/main/conf/oozie-env.sh
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean package -DskipTests -Phadoop-2 -Dhadoop.version=${HADOOP_VERSION} -Dassembly.ignorePermissions assembly:single

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/oozie ${STAGEDIR}${PREFIX}/oozie/libext ${STAGEDIR}${PREFIX}/oozie/lib ${STAGEDIR}${PREFIX}/oozie/bin ${STAGEDIR}${PREFIX}/oozie/conf ${STAGEDIR}${PREFIX}/oozie/conf/action-conf
	cd ${WRKSRC}/distro/target/oozie-${PORTVERSION}-distro/oozie-${PORTVERSION}/bin && ${INSTALL_SCRIPT} addtowar.sh oozie oozie-setup.sh oozie-sys.sh oozied.sh ooziedb.sh ${STAGEDIR}${PREFIX}/oozie/bin/
	cd ${WRKSRC}/webapp/target/oozie-webapp-${PORTVERSION}/WEB-INF/lib && ${INSTALL_DATA} *.jar ${STAGEDIR}${PREFIX}/oozie/lib/
	cd ${WRKSRC}/distro/target/oozie-${PORTVERSION}-distro/oozie-${PORTVERSION}/conf && ${INSTALL_DATA} oozie-default.xml.reference oozie-env.sh oozie-log4j.properties ${STAGEDIR}${PREFIX}/oozie/conf/
	${INSTALL_DATA} ${WRKSRC}/distro/target/oozie-${PORTVERSION}-distro/oozie-${PORTVERSION}/conf/action-conf/hive.xml ${STAGEDIR}${PREFIX}/oozie/conf/action-conf/
	${INSTALL_DATA} ${WRKSRC}/distro/target/oozie-${PORTVERSION}-distro/oozie-${PORTVERSION}/conf/oozie-site.xml ${STAGEDIR}${PREFIX}/oozie/conf/oozie-site.xml.sample
	cd ${WRKSRC}/distro/target/oozie-${PORTVERSION}-distro/oozie-${PORTVERSION} && ${COPYTREE_SHARE} "libtools oozie-client-${PORTVERSION}.tar.gz oozie-core oozie-examples.tar.gz oozie-server oozie-sharelib-${PORTVERSION}.tar.gz oozie.war" ${STAGEDIR}${PREFIX}/oozie/
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/oozie/oozie-server/bin/catalina.sh ${STAGEDIR}${PREFIX}/oozie/oozie-server/bin/setclasspath.sh
	${FIND} ${STAGEDIR}${PREFIX}/oozie/oozie-server/conf -name '*.xml' -or -name '*.properties' | ${XARGS} ${CHMOD} 644
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ext-2.2.zip ${STAGEDIR}${PREFIX}/oozie/libext/
	cd ${PREFIX}/share/hadoop/common/lib && ${INSTALL_DATA} activation-1.1.jar avro-1.7.4.jar commons-beanutils-1.7.0.jar commons-beanutils-core-1.8.0.jar commons-cli-1.2.jar commons-codec-1.4.jar commons-collections-3.2.2.jar commons-compress-1.4.1.jar commons-configuration-1.6.jar commons-digester-1.8.jar commons-httpclient-3.1.jar commons-io-2.4.jar commons-lang-2.6.jar commons-logging-1.1.3.jar commons-math3-3.1.1.jar commons-net-3.1.jar guava-11.0.2.jar httpclient-4.2.5.jar httpcore-4.2.5.jar jackson-core-asl-1.9.13.jar jackson-mapper-asl-1.9.13.jar jaxb-api-2.2.2.jar jersey-core-1.9.jar jetty-util-6.1.14.jar jsr305-3.0.0.jar log4j-1.2.17.jar paranamer-2.3.jar protobuf-java-2.5.0.jar servlet-api-2.5.jar slf4j-api-1.7.10.jar slf4j-log4j12-1.7.10.jar snappy-java-1.0.4.1.jar stax-api-1.0-2.jar xmlenc-0.52.jar xz-1.0.jar zookeeper-3.4.6.jar ${STAGEDIR}${PREFIX}/oozie/libext/
	cd ${PREFIX}/share/hadoop && ${INSTALL_DATA} common/lib/hadoop-annotations-${HADOOP_VERSION}.jar common/lib/hadoop-auth-${HADOOP_VERSION}.jar common/hadoop-common-${HADOOP_VERSION}.jar hdfs/hadoop-hdfs-${HADOOP_VERSION}.jar mapreduce/hadoop-mapreduce-client-app-${HADOOP_VERSION}.jar mapreduce/hadoop-mapreduce-client-common-${HADOOP_VERSION}.jar mapreduce/hadoop-mapreduce-client-core-${HADOOP_VERSION}.jar mapreduce/hadoop-mapreduce-client-jobclient-${HADOOP_VERSION}.jar mapreduce/hadoop-mapreduce-client-shuffle-${HADOOP_VERSION}.jar yarn/hadoop-yarn-api-${HADOOP_VERSION}.jar yarn/hadoop-yarn-client-${HADOOP_VERSION}.jar yarn/hadoop-yarn-common-${HADOOP_VERSION}.jar yarn/hadoop-yarn-server-common-${HADOOP_VERSION}.jar ${STAGEDIR}${PREFIX}/oozie/libext/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/hadoop-client-${HADOOP_VERSION}.jar ${STAGEDIR}${PREFIX}/oozie/libext/
	cd ${STAGEDIR}${PREFIX}/oozie && bin/oozie-setup.sh prepare-war
	${MKDIR} ${STAGEDIR}${OOZIE_RUNDIR}
	${MKDIR} ${STAGEDIR}${OOZIE_LOGDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/oozie/data

.include <bsd.port.mk>
