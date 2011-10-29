# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	gslin@gslin.org
COMMENT=	Open source distributed database management system

LICENSE=	ASL

JAVA_VERSION=	1.6+
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''
USE_JAVA=	yes
USE_RC_SUBR=	cassandra

CONFIGS=	access.properties \
		cassandra-topology.properties \
		cassandra.yaml \
		log4j-server.properties \
		log4j-tools.properties \
		passwd.properties
SCRIPTS=	cassandra \
		cassandra-cli \
		json2sstable \
		nodetool \
		repaircluster \
		sstable2json \
		sstablekeys \
		sstableloader

OPTIONS=	MX4J "Enable HTTP interface for JMX" Off

.include <bsd.port.options.mk>

.if defined(WITH_MX4J)
RUN_DEPENDS+=	${JAVAJARDIR}/mx4j-tools.jar:${PORTSDIR}/java/mx4j
PLIST_SUB+=	MX4J=""
.else
PLIST_SUB+=	MX4J="@comment "
.endif

post-extract:
	@${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server
	@${CP} ${SCRIPTDIR}/repaircluster ${WRKSRC}/bin
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool \
		${WRKSRC}/bin/sstableloader
	@${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${DATADIR}
	@cd ${DATADIR}/bin/ && ${CHMOD} ${BINMODE} ${SCRIPTS}
	@${LN} -s ${DATADIR}/bin/cassandra-cli ${PREFIX}/bin/cassandra-cli
	@${LN} -s ${DATADIR}/bin/nodetool ${PREFIX}/bin/nodetool
	@${LN} -s ${DATADIR}/bin/sstableloader ${PREFIX}/bin/sstableloader
	@${LN} -s ${DATADIR}/bin/repaircluster ${PREFIX}/bin/repaircluster
.ifdef (WITH_MX4J)
	@${LN} -s ${LOCALBASE}/share/java/classes/mx4j-tools.jar ${DATADIR}/lib/mx4j-tools.jar
.endif

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
