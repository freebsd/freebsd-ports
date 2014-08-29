# $FreeBSD$

PORTNAME=	cassandra
PORTVERSION=	2.0.10
CATEGORIES=	databases java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
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
		log4j-server.properties \
		log4j-tools.properties \
		cassandra-rackdc.properties \
		commitlog_archiving.properties
SCRIPTS=	cassandra \
		cassandra-cli \
		json2sstable \
		nodetool \
		sstable2json \
		sstablekeys \
		sstableloader \
		sstablescrub

CONFLICTS_INSTALL=	cassandra-1.*

OPTIONS_DEFINE=	MX4J JNA CQL DOCS
OPTIONS_SUB=	yes

MX4J_DESC=	Enable HTTP interface for JMX
JNA_DESC=	Use JNA native access
CQL_DESC=	Install cqlsh
DOCS_DESC=	Install javadoc documentation

SUB_FILES=	repaircluster

.include <bsd.port.options.mk>

RUN_DEPENDS+=	${JAVALIBDIR}/snappy-java.jar:${PORTSDIR}/archivers/snappy-java

MX4J_RUN_DEPENDS=	${JAVAJARDIR}/mx4j-tools.jar:${PORTSDIR}/java/mx4j
JNA_RUN_DEPENDS=	${JAVAJARDIR}/jna.jar:${PORTSDIR}/devel/jna
CQL_USE=	python=yes

PORTDOCS=	javadoc *.txt

.if ${PORT_OPTIONS:MCQL}
SCRIPTS+=	cqlsh
USES=		python:2
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
	${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool \
		${WRKSRC}/bin/sstableloader \
		${WRKSRC}/bin/sstable2json \
		${WRKSRC}/bin/json2sstable \
		${WRKSRC}/bin/sstablekeys
	${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh
	${RM} -f ${WRKSRC}/conf/*.orig
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
	${LN} -sf ${DATADIR}/bin/cassandra-cli ${STAGEDIR}${PREFIX}/bin/cassandra-cli
	${LN} -sf ${DATADIR}/bin/nodetool ${STAGEDIR}${PREFIX}/bin/nodetool
	${LN} -sf ${DATADIR}/bin/sstableloader ${STAGEDIR}${PREFIX}/bin/sstableloader
	${LN} -sf ${DATADIR}/bin/repaircluster ${STAGEDIR}${PREFIX}/bin/repaircluster
	${LN} -sf ${DATADIR}/bin/json2sstable ${STAGEDIR}${PREFIX}/bin/json2sstable
	${LN} -sf ${DATADIR}/bin/sstable2json ${STAGEDIR}${PREFIX}/bin/sstable2json
	${LN} -sf ${DATADIR}/bin/sstablekeys ${STAGEDIR}${PREFIX}/bin/sstablekeys
	${LN} -sf ${DATADIR}/bin/sstablescrub ${STAGEDIR}${PREFIX}/bin/sstablescrub

.if ${PORT_OPTIONS:MCQL}
	${LN} -sf ${DATADIR}/bin/cqlsh ${STAGEDIR}${PREFIX}/bin/cqlsh
.endif
.if ${PORT_OPTIONS:MMX4J}
	${LN} -sf ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${STAGEDIR}${DATADIR}/lib/mx4j-tools.jar
.endif
.if ${PORT_OPTIONS:MJNA}
	${LN} -sf ${LOCALBASE}/share/java/classes/jna.jar ${STAGEDIR}${DATADIR}/lib/jna.jar
	${LN} -sf ${LOCALBASE}/share/java/classes/jna-platform.jar ${STAGEDIR}${DATADIR}/lib/jna-platform.jar
.endif

.include <bsd.port.mk>
