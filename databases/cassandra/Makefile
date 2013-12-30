# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cassandra
PORTVERSION=	1.1.12
CATEGORIES=	databases java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	hsn@sendmail.cz
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

OPTIONS_DEFINE=	MX4J JNA CQL DOCS
MX4J_DESC=	Enable HTTP interface for JMX
JNA_DESC=	Use JNA native access
CQL_DESC=	Install cqlsh
DOCS_DESC=	Install javadoc documentation

SUB_FILES=	repaircluster

NO_STAGE=	yes
.include <bsd.port.options.mk>

RUN_DEPENDS+=	${JAVALIBDIR}/snappy-java.jar:${PORTSDIR}/archivers/snappy-java

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	javadoc *.txt
.endif

.if ${PORT_OPTIONS:MMX4J}
RUN_DEPENDS+=	${JAVAJARDIR}/mx4j-tools.jar:${PORTSDIR}/java/mx4j
PLIST_SUB+=	MX4J=""
.else
PLIST_SUB+=	MX4J="@comment "
.endif
.if ${PORT_OPTIONS:MJNA}
RUN_DEPENDS+=	${JAVAJARDIR}/jna.jar:${PORTSDIR}/devel/jna
PLIST_SUB+=	JNA=""
.else
PLIST_SUB+=	JNA="@comment "
.endif
.if ${PORT_OPTIONS:MCQL}
USE_PYTHON=	yes
PLIST_SUB+=	CQL=""
SCRIPTS+=	cqlsh
.else
PLIST_SUB+=	CQL="@comment "
.endif

post-extract:
	@${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server \
		${WRKSRC}/tools/bin/*.bat ${WRKSRC}/lib/snappy-java-*.jar
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor
.if empty(PORT_OPTIONS:MCQL)
	@${RM} -r ${WRKSRC}/pylib
	@${RM} ${WRKSRC}/bin/cqlsh
	@${RM} ${WRKSRC}/lib/*.zip
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool \
		${WRKSRC}/bin/sstableloader \
		${WRKSRC}/bin/sstable2json \
		${WRKSRC}/bin/json2sstable \
		${WRKSRC}/bin/sstablekeys
	@${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh
	@${RM} -f ${WRKSRC}/conf/*.orig
.if ${PORT_OPTIONS:MCQL}
	@${REINPLACE_CMD} -e 's|os.path.dirname(__file__)|"${DATADIR}/bin"|' \
		${WRKSRC}/bin/cqlsh
.endif

do-build:
.if ${PORT_OPTIONS:MCQL}
	@${PYTHON_CMD} -m compileall ${WRKSRC}/pylib
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${DATADIR}
	@${LN} -s ${JAVAJARDIR}/snappy-java.jar ${DATADIR}/lib/snappy-java.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${MV} ${DATADIR}/javadoc ${DOCSDIR}
	@${MV} ${DATADIR}/*.txt ${DOCSDIR}
.else
	${RM} -r ${DATADIR}/javadoc ${DATADIR}/*.txt
.endif
	@cd ${DATADIR}/bin/ && ${CHMOD} ${BINMODE} ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/repaircluster ${DATADIR}/bin
	@${LN} -s ${DATADIR}/bin/cassandra-cli ${PREFIX}/bin/cassandra-cli
	@${LN} -s ${DATADIR}/bin/nodetool ${PREFIX}/bin/nodetool
	@${LN} -s ${DATADIR}/bin/sstableloader ${PREFIX}/bin/sstableloader
	@${LN} -s ${DATADIR}/bin/repaircluster ${PREFIX}/bin/repaircluster
	@${LN} -s ${DATADIR}/bin/json2sstable ${PREFIX}/bin/json2sstable
	@${LN} -s ${DATADIR}/bin/sstable2json ${PREFIX}/bin/sstable2json
	@${LN} -s ${DATADIR}/bin/sstablekeys ${PREFIX}/bin/sstablekeys
	@${LN} -s ${DATADIR}/bin/sstablescrub ${PREFIX}/bin/sstablescrub

.if ${PORT_OPTIONS:MCQL}
	@${LN} -s ${DATADIR}/bin/cqlsh ${PREFIX}/bin/cqlsh
.endif
.if ${PORT_OPTIONS:MMX4J}
	@${LN} -s ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${DATADIR}/lib/mx4j-tools.jar
.endif
.if ${PORT_OPTIONS:MJNA}
	@${LN} -s ${LOCALBASE}/share/java/classes/jna.jar ${DATADIR}/lib/jna.jar
	@${LN} -s ${LOCALBASE}/share/java/classes/jna-platform.jar ${DATADIR}/lib/jna-platform.jar
.endif

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
