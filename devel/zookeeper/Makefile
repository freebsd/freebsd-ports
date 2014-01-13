# Created by: gnn@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.3.6
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	zookeeper/zookeeper-${PORTVERSION}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	A Coordination Service for Distributed Applications

LICENSE=	APACHE20

LIB_DEPENDS=	cppunit:${PORTSDIR}/devel/cppunit
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	C PYTHON
C_DESC=	Build C library bindings and command line tool
OPTIONS_DEFAULT=	C PYTHON DOC

USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

USE_RC_SUBR=	zookeeper

ZOOKEEPER_LOGDIR=	/var/log/${PORTNAME}
ZOOKEEPER_RUNDIR=	/var/run/${PORTNAME}

PYTHON_BINDING_WRKSRC=	${WRKSRC}/src/contrib/zkpython
PYDISTUTILS_PKGNAME=	ZooKeeper
PYDISTUTILS_PKGVERSION=	0.4

CONFIGURE_WRKSRC=	${WRKSRC}/src/c

SCRIPTS=	zkCleanup.sh \
		zkCli.sh \
		zkEnv.sh \
		zkServer.sh
PORTDOCS=	*

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_LIST=	ZOOKEEPER_LOGDIR=${ZOOKEEPER_LOGDIR} \
		ZOOKEEPER_RUNDIR=${ZOOKEEPER_RUNDIR}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MC}
USE_AUTOTOOLS=	automake autoconf libtool
USE_LDCONFIG=	yes
PLIST_SUB+=	WITH_C=""
.else
PLIST_SUB+=	WITH_C="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MC}
#run-autotools:	run-autotools-autoreconf

#run-autotools-autoreconf:
run-autotools:
	@cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -if
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|executable="python"|executable="${PYTHON_CMD}"|' \
		${PYTHON_BINDING_WRKSRC}/build.xml

do-build:
.if ${PORT_OPTIONS:MC}
	cd ${CONFIGURE_WRKSRC} && \
	${MAKE}
.endif
.if ${PORT_OPTIONS:MPYTHON}
	cd ${PYTHON_BINDING_WRKSRC} && \
	ant compile
.endif

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}
	${MKDIR} ${PREFIX}/${PORTNAME}/bin
	${MKDIR} ${ZOOKEEPER_LOGDIR}
	${MKDIR} ${ZOOKEEPER_RUNDIR}
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/${PORTNAME}/bin
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${PREFIX}/${PORTNAME}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${PREFIX}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/*.jar ${PREFIX}/${PORTNAME}
.if ${PORT_OPTIONS:MC}
	cd ${CONFIGURE_WRKSRC} && \
	${MAKE} install
.endif
.if ${PORT_OPTIONS:MPYTHON}
	cd ${PYTHON_BINDING_WRKSRC} && \
	ant install
.endif
.if ${PORT_OPTIONS:MDOC}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
