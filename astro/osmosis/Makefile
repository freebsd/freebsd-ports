# New ports collection makefile for:	osmosis
# Date created:		2009/09/21
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osmosis
PORTVERSION=	0.40.1
CATEGORIES=	astro java
MASTER_SITES=	http://bretth.dev.openstreetmap.org/osmosis-build/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line Java app for processing OpenStreetMap data

NO_BUILD=	yes

USE_JAVA=	YES
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	osmosis

JAVAJARDIR_REL=	 ${JAVAJARDIR:C,${PREFIX}/?,,}
JARFILES=	aopalliance-1.0.jar \
		commons-codec-1.5.jar \
		commons-compress-1.2.jar \
		commons-dbcp-1.4.jar \
		commons-logging-1.1.1.jar \
		commons-pool-1.5.4.jar \
		jpf-1.5.jar \
		mysql-connector-java-5.1.18.jar \
		osmosis-apidb-${PORTVERSION}.jar \
		osmosis-areafilter-${PORTVERSION}.jar \
		osmosis-core-${PORTVERSION}.jar \
		osmosis-dataset-${PORTVERSION}.jar \
		osmosis-extract-${PORTVERSION}.jar \
		osmosis-hstore-${PORTVERSION}.jar \
		osmosis-pbf-${PORTVERSION}.jar \
		osmosis-pgsimple-${PORTVERSION}.jar \
		osmosis-pgsnapshot-${PORTVERSION}.jar \
		osmosis-replication-${PORTVERSION}.jar \
		osmosis-set-${PORTVERSION}.jar \
		osmosis-tagfilter-${PORTVERSION}.jar \
		osmosis-xml-${PORTVERSION}.jar \
		osmpbf-1.1.1-754a33af.jar \
		plexus-classworlds-2.4.jar \
		postgis-jdbc-1.3.3.jar \
		postgresql-9.0-801.jdbc4.jar \
		protobuf-java-2.4.1.jar \
		spring-aop-3.0.6.RELEASE.jar \
		spring-asm-3.0.6.RELEASE.jar \
		spring-beans-3.0.6.RELEASE.jar \
		spring-context-3.0.6.RELEASE.jar \
		spring-core-3.0.6.RELEASE.jar \
		spring-expression-3.0.6.RELEASE.jar \
		spring-jdbc-3.0.6.RELEASE.jar \
		spring-tx-3.0.6.RELEASE.jar \
		stax2-api-3.1.1.jar \
		woodstox-core-lgpl-4.1.2.jar \
		xercesImpl-2.9.1.jar

CONFFILES=	plexus.conf

do-install:
	@${MKDIR} ${DATADIR}/lib/default
	${INSTALL_DATA} ${JARFILES:S,^,${WRKSRC}/lib/default/,} ${DATADIR}/lib/default
	@${MKDIR} ${DATADIR}/config
	${INSTALL_DATA} ${CONFFILES:S,^,${WRKSRC}/config/,} ${DATADIR}/config
	${INSTALL_SCRIPT} ${WRKDIR}/osmosis ${PREFIX}/bin/osmosis
	cd ${WRKSRC} && ${COPYTREE_SHARE} script ${DATADIR}/

.include <bsd.port.mk>
