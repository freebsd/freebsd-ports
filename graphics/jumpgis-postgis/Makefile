# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	jumpgis-postgis
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	graphics databases java geography
MASTER_SITES=	http://postgis.refractions.net/download/
DISTNAME=	postgisdriver-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JUMP support for reading and writing a PostGIS database

DEPRECATED=	Depends on expiring graphics/jumpgis
EXPIRATION_DATE=	2014-03-10

RUN_DEPENDS=	jumpgis:${PORTSDIR}/graphics/jumpgis

USES=		zip
TARGET_DIR=	${PREFIX}/jumpgis
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} " >> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib/ext/
	${INSTALL_DATA} ${WRKSRC}/lib/ext/postgisdriver-1.1.0.jar ${TARGET_DIR}/lib/ext/
	${INSTALL_DATA} ${WRKSRC}/lib/ext/pg74jdbc3.jar ${TARGET_DIR}/lib/

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
