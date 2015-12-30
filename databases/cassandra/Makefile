# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cassandra
PORTVERSION=	1.2.18
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	APACHE/cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Open source distributed database management system

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVALIBDIR}/snappy-java.jar:${PORTSDIR}/archivers/snappy-java

DEPRECATED=	1.2.x has reached EOL, upgrade to a supported version of Cassandra
EXPIRATION_DATE=	2016-03-27

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
		cqlsh \
		json2sstable \
		nodetool \
		sstable2json \
		sstablekeys \
		sstableloader \
		sstablescrub \
		cassandra-shuffle

OPTIONS_DEFINE=	MX4J JNA CQL DOCS
MX4J_DESC=	Enable HTTP interface for JMX
JNA_DESC=	Use JNA native access
CQL_DESC=	Install cqlsh
DOCS_DESC=	Install javadoc documentation
OPTIONS_SUB=	yes

SUB_FILES=	repaircluster

MX4J_RUN_DEPENDS=	${JAVAJARDIR}/mx4j-tools.jar:${PORTSDIR}/java/mx4j
JNA_RUN_DEPENDS=	${JAVAJARDIR}/jna.jar:${PORTSDIR}/devel/jna
CQL_USES=		python

PORTDOCS=	javadoc *.txt

.include <bsd.port.options.mk>

post-extract:
	@${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server \
		${WRKSRC}/tools/bin/*.bat ${WRKSRC}/lib/snappy-java-*.jar \
		${WRKSRC}/lib/licenses/snappy-java*.txt
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool \
		${WRKSRC}/bin/sstableloader \
		${WRKSRC}/bin/sstable2json \
		${WRKSRC}/bin/json2sstable \
		${WRKSRC}/bin/sstablekeys \
		${WRKSRC}/bin/cassandra-shuffle
	@${REINPLACE_CMD} -e 's|\`dirname "\$$\0"\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh
	@${RM} -f ${WRKSRC}/conf/*.orig
	@${REINPLACE_CMD} -e 's|os.path.dirname(__file__)|"${DATADIR}/bin"|' \
		${WRKSRC}/bin/cqlsh

do-build:
.if ${PORT_OPTIONS:MCQL}
	${PYTHON_CMD} -m compileall ${WRKSRC}/pylib
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${LN} -s ${JAVAJARDIR}/snappy-java.jar ${STAGEDIR}${DATADIR}/lib/snappy-java.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DATADIR}/javadoc ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${DATADIR}/*.txt ${STAGEDIR}${DOCSDIR}
	@cd ${STAGEDIR}${DATADIR}/bin/ && ${CHMOD} ${BINMODE} ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/repaircluster ${STAGEDIR}${DATADIR}/bin
	${LN} -s ${DATADIR}/bin/cassandra-cli ${STAGEDIR}${PREFIX}/bin/cassandra-cli
	${LN} -s ${DATADIR}/bin/nodetool ${STAGEDIR}${PREFIX}/bin/nodetool
	${LN} -s ${DATADIR}/bin/sstableloader ${STAGEDIR}${PREFIX}/bin/sstableloader
	${LN} -s ${DATADIR}/bin/repaircluster ${STAGEDIR}${PREFIX}/bin/repaircluster
	${LN} -s ${DATADIR}/bin/json2sstable ${STAGEDIR}${PREFIX}/bin/json2sstable
	${LN} -s ${DATADIR}/bin/sstable2json ${STAGEDIR}${PREFIX}/bin/sstable2json
	${LN} -s ${DATADIR}/bin/sstablekeys ${STAGEDIR}${PREFIX}/bin/sstablekeys
	${LN} -s ${DATADIR}/bin/sstablescrub ${STAGEDIR}${PREFIX}/bin/sstablescrub
	${LN} -s ${DATADIR}/bin/cassandra-shuffle ${STAGEDIR}${PREFIX}/bin/cassandra-shuffle
	${LN} -s ${DATADIR}/bin/cqlsh ${STAGEDIR}${PREFIX}/bin/cqlsh
	${LN} -s ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${STAGEDIR}${DATADIR}/lib/mx4j-tools.jar
	${LN} -s ${LOCALBASE}/share/java/classes/jna.jar ${STAGEDIR}${DATADIR}/lib/jna.jar
	${LN} -s ${LOCALBASE}/share/java/classes/jna-platform.jar ${STAGEDIR}${DATADIR}/lib/jna-platform.jar

.include <bsd.port.mk>
