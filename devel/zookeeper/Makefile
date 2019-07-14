# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.5.5
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/current
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Coordination Service for Distributed Applications

LICENSE=	APACHE20

RUN_DEPENDS=	libzookeeper>=${PORTVERSION}:devel/libzookeeper

USERS=	zookeeper
GROUPS=	zookeeper

ZOOKEEPER_CONFS=	configuration.xsl log4j.properties zoo.cfg

DATADIR=		${JAVASHAREDIR}/${PORTNAME}

ZOOKEEPER_DBDIR?=	/var/db/zookeeper
ZOOKEEPER_LOGDIR?=	/var/log/zookeeper

SUB_FILES=	zookeeper zkCli.sh
SUB_LIST=	JAVA=${JAVA} \
		JAVALIBDIR=${JAVALIBDIR} \
		ETCDIR=${ETCDIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR}

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		ZOOKEEPER_DBDIR=${ZOOKEEPER_DBDIR} \
		ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR}

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_RUN=	yes
USE_RC_SUBR=	zookeeper

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} "/dataDir/s|=.*|=${ZOOKEEPER_DBDIR}|" ${WRKDIR}/${DISTNAME}/conf/zoo_sample.cfg
	@${MV} ${WRKDIR}/${DISTNAME}/conf/zoo_sample.cfg ${WRKDIR}/${DISTNAME}/conf/zoo.cfg

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in ${ZOOKEEPER_CONFS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/conf/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-name *\.jar")

	${INSTALL_SCRIPT} ${WRKDIR}/zkCli.sh ${STAGEDIR}${PREFIX}/bin/

	${MKDIR} ${STAGEDIR}${ZOOKEEPER_LOGDIR}
	${MKDIR} ${STAGEDIR}${ZOOKEEPER_DBDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/${DISTNAME}/docs && \
	${TAR} -cf - . | ${TAR} -xf - -C ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
