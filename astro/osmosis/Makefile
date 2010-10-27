# New ports collection makefile for:	osmosis
# Date created:		2009/09/21
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osmosis
PORTVERSION=	0.37
CATEGORIES=	astro java
MASTER_SITES=	http://bretth.dev.openstreetmap.org/osmosis-build/
EXTRACT_SUFX=	.tgz

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	A command line java app for processing OpenStreetMap data

NO_BUILD=	yes

USE_JAVA=	YES
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	osmosis

JAVAJARDIR_REL=	 ${JAVAJARDIR:C,${PREFIX}/?,,}
JARFILES=	aopalliance-1.0.jar \
		commons-codec-1.4.jar \
		commons-compress-1.0.jar \
		commons-dbcp-1.4.jar \
		commons-logging-1.1.1.jar \
		commons-pool-1.5.4.jar \
		jpf-1.5.jar \
		mysql-connector-java-5.1.10.jar \
		osmbin-1.0-6d760534.jar \
		osmosis-apidb-0.37.jar \
		osmosis-areafilter-0.37.jar \
		osmosis-binary-0.37.jar \
		osmosis-core-0.37.jar \
		osmosis-dataset-0.37.jar \
		osmosis-extract-0.37.jar \
		osmosis-hstore-0.2.jar \
		osmosis-pgsnapshot-0.37.jar \
		osmosis-replication-0.37.jar \
		osmosis-set-0.37.jar \
		osmosis-tagfilter-0.37.jar \
		osmosis-xml-0.37.jar \
		plexus-classworlds-2.2.2.jar \
		postgis-jdbc-1.3.3.jar \
		postgresql-8.4-701.jdbc4.jar \
		protobuf-java-2.3.0.jar \
		spring-aop-3.0.3.RELEASE.jar \
		spring-asm-3.0.3.RELEASE.jar \
		spring-beans-3.0.3.RELEASE.jar \
		spring-context-3.0.3.RELEASE.jar \
		spring-core-3.0.3.RELEASE.jar \
		spring-expression-3.0.3.RELEASE.jar \
		spring-jdbc-3.0.3.RELEASE.jar \
		spring-tx-3.0.3.RELEASE.jar \
		stax2-api-3.0.2.jar \
		woodstox-core-lgpl-4.0.3.jar \
		xercesImpl-2.9.1.jar

CONFFILES=	plexus.conf \
		osmosis-plugins.conf

do-install:
	@${MKDIR} ${DATADIR}/lib/default
	${INSTALL_DATA} ${JARFILES:S,^,${WRKSRC}/lib/default/,} ${DATADIR}/lib/default
	@${MKDIR} ${DATADIR}/config
	${INSTALL_DATA} ${CONFFILES:S,^,${WRKSRC}/config/,} ${DATADIR}/config
	${INSTALL_SCRIPT} ${WRKDIR}/osmosis ${PREFIX}/bin/osmosis

.include <bsd.port.mk>
