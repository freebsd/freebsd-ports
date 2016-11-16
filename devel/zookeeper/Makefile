# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.4.9
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/current

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Coordination Service for Distributed Applications

RUN_DEPENDS=	slf4j>=1.7.5:devel/slf4j \
		netty>=3.5.5:java/netty \
		jline>=0.9.94:devel/jline \
		log4j>=1.2.16:devel/log4j \
		libzookeeper>=3.4.7:devel/libzookeeper

USERS=	zookeeper
GROUPS=	zookeeper

ZOOKEEPER_JAR=	${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar

ZOOKEEPER_DBDIR?=	/var/db/zookeeper
ZOOKEEPER_LOGDIR?=	/var/log/zookeeper

SUB_FILES=	zookeeper zkCli.sh zkServer.sh
SUB_LIST=	JAVA=${JAVA} \
		JAVALIBDIR=${JAVALIBDIR} \
		ETCDIR=${ETCDIR} \
		ZOOKEEPER_USER=${USERS} \
		ZOOKEEPER_GROUP=${GROUPS} \
		ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR}

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		ZOOKEEPER_DBDIR=${ZOOKEEPER_DBDIR} \
		ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR} \
		JAVALIBDIR=${JAVALIBDIR}

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes
USE_RC_SUBR=	zookeeper

PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} "/dataDir/s|=.*|=${ZOOKEEPER_DBDIR}|" ${WRKDIR}/${DISTNAME}/conf/zoo_sample.cfg
	@${RM} ${WRKDIR}/${DISTNAME}/conf/zoo_sample.cfg.bak

do-install:
	${CP} -Rp ${WRKDIR}/${DISTNAME}/conf/ ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${ZOOKEEPER_JAR} ${STAGEDIR}${JAVALIBDIR}
	(cd ${STAGEDIR}/${JAVAJARDIR} && ${LN} -nfs \
		${PORTNAME}-${PORTVERSION}.jar ${PORTNAME}.jar)

	${INSTALL_SCRIPT} ${WRKDIR}/zkCli.sh ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/zkServer.sh ${STAGEDIR}${PREFIX}/bin/

	${MKDIR} ${STAGEDIR}${ZOOKEEPER_LOGDIR}
	${MKDIR} ${STAGEDIR}${ZOOKEEPER_DBDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/${DISTNAME}/docs && \
	${TAR} -cf - . | ${TAR} -xf - -C ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
