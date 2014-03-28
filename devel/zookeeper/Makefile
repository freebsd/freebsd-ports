# Created by: gnn@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.4.6
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

OPTIONS_DEFINE=	DOC
DOC_DESC=	Install documentation
OPTIONS_DEFAULT=	DOC

NO_BUILD=	yes

SCRIPTS=	zkCleanup.sh \
		zkCli.sh \
		zkEnv.sh \
		zkServer.sh
PORTDOCS=	*

PLIST_SUB=	PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		RESETPREFIX=${PREFIX}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${STAGEDIR}${PREFIX}/${PORTNAME}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${PREFIX}/${PORTNAME}

post-install:
.if ${PORT_OPTIONS:MDOC}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	@${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

.include <bsd.port.post.mk>
