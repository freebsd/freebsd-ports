# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	1.0.6
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source distributed database management system

LICENSE=	AL2

JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk
REINPLACE_ARGS=	-i ''
USE_JAVA=	yes
USE_RC_SUBR=	cassandra

CONFIGS=	cassandra-topology.properties \
		cassandra.yaml \
		log4j-server.properties \
		log4j-tools.properties
SCRIPTS=	cassandra \
		cassandra-cli \
		json2sstable \
		nodetool \
		sstable2json \
		sstablekeys \
		sstableloader

OPTIONS=	MX4J "Enable HTTP interface for JMX" Off \
		JNA "Use JNA native access" Off \
		CQL "Install cqlsh" Off

SUB_FILES=	repaircluster

.include <bsd.port.options.mk>

.if defined(WITH_MX4J)
RUN_DEPENDS+=	${JAVAJARDIR}/mx4j-tools.jar:${PORTSDIR}/java/mx4j
PLIST_SUB+=	MX4J=""
.else
PLIST_SUB+=	MX4J="@comment "
.endif
.if defined(WITH_JNA)
RUN_DEPENDS+=	${JAVAJARDIR}/jna.jar:${PORTSDIR}/devel/jna
PLIST_SUB+=	JNA=""
.else
PLIST_SUB+=	JNA="@comment "
.endif
.if defined(WITH_CQL)
USE_PYTHON=	yes
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cql>=0:${PORTSDIR}/databases/py-cql
PLIST_SUB+=	CQL=""
SCRIPTS+=	cqlsh
.else
PLIST_SUB+=	CQL="@comment "
.endif

post-extract:
	@${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor
	@${MV} ${WRKSRC}/bin/cqlshrc.sample ${WRKSRC}/conf
.if !defined(WITH_CQL)
	@${RM} -r ${WRKSRC}/pylib
	@${RM} ${WRKSRC}/bin/cqlsh
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool \
		${WRKSRC}/bin/sstableloader
	@${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh
	@${RM} -f ${WRKSRC}/conf/*.orig
.if defined(WITH_CQL)
	@${REINPLACE_CMD} -e 's|os.path.dirname(__file__)|"${DATADIR}/bin"|' \
		${WRKSRC}/bin/cqlsh
.endif

do-build:
.if defined(WITH_CQL)
	@${PYTHON_CMD} -m compileall ${WRKSRC}/pylib
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${DATADIR}
	@cd ${DATADIR}/bin/ && ${CHMOD} ${BINMODE} ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/repaircluster ${DATADIR}/bin
	@${LN} -s ${DATADIR}/bin/cassandra-cli ${PREFIX}/bin/cassandra-cli
	@${LN} -s ${DATADIR}/bin/nodetool ${PREFIX}/bin/nodetool
	@${LN} -s ${DATADIR}/bin/sstableloader ${PREFIX}/bin/sstableloader
	@${LN} -s ${DATADIR}/bin/repaircluster ${PREFIX}/bin/repaircluster
.if defined(WITH_CQL)
	@${LN} -s ${DATADIR}/bin/cqlsh ${PREFIX}/bin/cqlsh
.endif
.if defined(WITH_MX4J)
	@${LN} -s ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${DATADIR}/lib/mx4j-tools.jar
.endif
.if defined(WITH_JNA)
	@${LN} -s ${LOCALBASE}/share/java/classes/jna.jar ${DATADIR}/lib/jna.jar
	@${LN} -s ${LOCALBASE}/share/java/classes/jna-platform.jar ${DATADIR}/lib/jna-platform.jar
.endif

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
