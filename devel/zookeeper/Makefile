# Created by: gnn@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.4.6
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	zookeeper/zookeeper-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Service for maintaining distributed configuration, naming and locks

LICENSE=	APACHE20

LIB_DEPENDS=	libcppunit.so:${PORTSDIR}/devel/cppunit
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

USE_RC_SUBR=	zookeeper

NO_BUILD=	yes

SCRIPTS=	zkCleanup.sh \
		zkCli.sh \
		zkEnv.sh \
		zkServer.sh
PORTDOCS=	*

PLIST_SUB=	PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}

ZOOKEEPER_LOGDIR?=	/var/log/${PORTNAME}
ZOOKEEPER_RUNDIR?=	/var/run/${PORTNAME}

SUB_LIST+=	ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR} \
		ZOOKEEPER_RUNDIR=${ZOOKEEPER_RUNDIR} \
		JAVA_HOME=${JAVA_HOME}

post-patch:
.for f in ${SCRIPTS}
	${REINPLACE_CMD} -e "s|bash|${LOCALBASE}/bin/bash|" ${WRKSRC}/bin/${f}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${STAGEDIR}${PREFIX}/${PORTNAME}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${PREFIX}/${PORTNAME}
	${LN} -s ${PREFIX}/${PORTNAME}/bin/zkCli.sh ${STAGEDIR}${PREFIX}/bin/zkCli.sh

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${ZOOKEEPER_LOGDIR}
	@${MKDIR} ${STAGEDIR}${ZOOKEEPER_RUNDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${DOCSDIR}/skin/translations
	${RM} -r ${STAGEDIR}${DOCSDIR}/skin/scripts
	${RM} -r ${STAGEDIR}${DOCSDIR}/skin/css
.endif

.include <bsd.port.mk>
