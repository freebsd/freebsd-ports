# $FreeBSD$

PORTNAME=	cassandra
PORTVERSION=	2.1.1
CATEGORIES=	databases java
MASTER_SITES=	APACHE/cassandra/${PORTVERSION}
PKGNAMESUFFIX=	2
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	admins@perceptyx.com
COMMENT=	Open source distributed database management system

LICENSE=	APACHE20

JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
REINPLACE_ARGS=	-i ''
USE_JAVA=	yes
USE_RC_SUBR=	cassandra

CONFIGS=	cassandra-topology.properties \
		cassandra.yaml \
		cassandra-rackdc.properties \
		commitlog_archiving.properties
SCRIPTS=	cassandra \
		cassandra-cli \
		debug-cql \
		nodetool \
		sstablekeys \
		sstableloader \
		sstablescrub \
		sstableupgrade

CONFLICTS_INSTALL=	cassandra-1.*

OPTIONS_DEFINE=	MX4J CQL DOCS
OPTIONS_SUB=	yes

MX4J_DESC=	Enable HTTP interface for JMX
CQL_DESC=	Install cqlsh
DOCS_DESC=	Install javadoc documentation

SUB_FILES=	repaircluster

.include <bsd.port.options.mk>

RUN_DEPENDS+=	${JAVALIBDIR}/snappy-java.jar:archivers/snappy-java

MX4J_RUN_DEPENDS=	${JAVAJARDIR}/mx4j-tools.jar:java/mx4j
CQL_USES=	python:2

PORTDOCS=	javadoc *.txt

.if ${PORT_OPTIONS:MCQL}
SCRIPTS+=	cqlsh
.endif

post-extract:
	${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server \
		${WRKSRC}/tools/bin/*.bat ${WRKSRC}/lib/snappy-java-*.jar
.for i in ${CONFIGS}
	${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor
.if empty(PORT_OPTIONS:MCQL)
	${RM} -r ${WRKSRC}/pylib
	${RM} ${WRKSRC}/bin/cqlsh
	${RM} ${WRKSRC}/lib/*.zip
.endif

post-patch:
.for i in ${SCRIPTS}
	${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/${i}
.endfor
	${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh
	${RM} ${WRKSRC}/conf/*.orig
.if ${PORT_OPTIONS:MCQL}
	${REINPLACE_CMD} -e 's|os.path.dirname(__file__)|"${DATADIR}/bin"|' \
		${WRKSRC}/bin/cqlsh
.endif

do-build:
.if ${PORT_OPTIONS:MCQL}
	${PYTHON_CMD} -m compileall ${WRKSRC}/pylib
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${LN} -sf ${JAVAJARDIR}/snappy-java.jar ${STAGEDIR}${DATADIR}/lib/snappy-java.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DATADIR}/javadoc ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DATADIR}/*.txt ${STAGEDIR}${DOCSDIR}
	cd ${STAGEDIR}${DATADIR}/bin/ && ${CHMOD} ${BINMODE} ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/repaircluster ${STAGEDIR}${DATADIR}/bin
.for i in ${SCRIPTS}
	${LN} -sf ${DATADIR}/bin/${i} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.if ${PORT_OPTIONS:MMX4J}
	${LN} -sf ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${STAGEDIR}${DATADIR}/lib/mx4j-tools.jar
.endif

.include <bsd.port.mk>
