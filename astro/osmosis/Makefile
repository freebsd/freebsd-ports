# New ports collection makefile for:	osmosis
# Date created:		2009/09/21
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osmosis
PORTVERSION=	0.31.2
CATEGORIES=	astro java
MASTER_SITES=	http://dev.openstreetmap.org/~bretth/osmosis-build/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	A command line java app for processing OpenStreetMap data

NO_BUILD=	yes

USE_JAVA=	YES
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	osmosis

FETCH_ARGS=	-pRr
JAVAJARDIR_REL=	 ${JAVAJARDIR:C,${PREFIX}/?,,}
JARFILES=	aopalliance-1.0.jar \
		bzip2-20090327.jar \
		commons-dbcp-1.2.2.jar \
		commons-logging-1.1.1.jar \
		commons-pool-1.3.jar \
		jpf-1.5.jar \
		mysql-connector-java-5.1.6.jar \
		postgis-1.3.2.jar \
		postgresql-8.3-603.jdbc4.jar \
		spring-beans-2.5.6.SEC01.jar \
		spring-context-2.5.6.SEC01.jar \
		spring-core-2.5.6.SEC01.jar \
		spring-jdbc-2.5.6.SEC01.jar \
		spring-tx-2.5.6.SEC01.jar \
		stax2-api-3.0.1.jar \
		woodstox-core-lgpl-4.0.3.jar

PLIST_FILES=	bin/osmosis ${JAVAJARDIR_REL}/osmosis.jar \
		${JARFILES:S,^,${DATADIR_REL}/,}

do-install:
	@${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKSRC}/osmosis.jar ${JAVAJARDIR}/
	@${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${JARFILES:S,^,${WRKSRC}/lib/default/,} ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/osmosis ${PREFIX}/bin/osmosis

.include <bsd.port.mk>
