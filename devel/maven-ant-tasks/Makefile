# New ports collection Makefile for:	maven-ant-tasks
# Date created:		June 2010
# Whom:			Chris Rees <utisoft@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	maven-ant-tasks
PORTVERSION=	2.1.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/source

MAINTAINER=	utisoft@gmail.com
COMMENT=	Allows Maven's artifact handling to be used from within an Ant build

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven2
RUN_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_ZIP=	yes
USE_JAVA=	1.5+

JAR_NAME=	${PORTNAME}-${PORTVERSION}.jar

PLIST_FILES=	%%JAVASHAREDIR%%/apache-ant/lib/${JAR_NAME}

do-build:
	@cd ${WRKSRC} && mvn package

do-install:
	@${INSTALL_DATA} "${WRKSRC}/target/${JAR_NAME}" ${JAVASHAREDIR}/apache-ant/lib/

.include <bsd.port.mk>
