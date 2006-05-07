# New ports collection makefile for:	JUMP PostGIS plugin
# Date created:				June 25 2004
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	jumpgis-postgis
PORTVERSION=	1.1.0
CATEGORIES=	graphics databases java
MASTER_SITES=	http://postgis.refractions.net/download/
DISTNAME=	postgisdriver-${PORTVERSION}

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	JUMP support for reading and writing a PostGIS database

RUN_DEPENDS=	jumpgis:${PORTSDIR}/graphics/jumpgis

TARGET_DIR=	${PREFIX}/jumpgis
USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${ECHO_MSG} " >> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib/ext/
	${INSTALL_DATA} ${WRKSRC}/lib/ext/postgisdriver-1.1.0.jar ${TARGET_DIR}/lib/ext/
	${INSTALL_DATA} ${WRKSRC}/lib/ext/pg74jdbc3.jar ${TARGET_DIR}/lib/

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
