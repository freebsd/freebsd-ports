# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	0.8.7
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
		sstable2json \
		sstablekeys \
		sstableloader

post-extract:
	@${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/stop-server
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' \
		${WRKSRC}/bin/cassandra-cli \
		${WRKSRC}/bin/nodetool
	@${REINPLACE_CMD} -e 's|\`dirname \$$\0\`/..|${DATADIR}|' \
		${WRKSRC}/bin/cassandra.in.sh

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${DATADIR}
	@cd ${DATADIR}/bin/ && ${CHMOD} u+x ${SCRIPTS}
	@${LN} -s ${DATADIR}/bin/cassandra-cli ${PREFIX}/bin/cassandra-cli
	@${LN} -s ${DATADIR}/bin/nodetool ${PREFIX}/bin/nodetool

post-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
