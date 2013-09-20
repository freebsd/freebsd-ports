# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	geoserver
PORTVERSION=	2.1.1
CATEGORIES=	databases geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer%20Extensions/${PORTVERSION}
PKGNAMESUFFIX=	-mysql-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A MySQL DataStore implementation for GeoServer

RUN_DEPENDS=	${LOCALBASE}/geoserver/start.jar:${PORTSDIR}/graphics/geoserver

USE_ZIP=	yes
NO_BUILD=	yes

GSLIBDIR=	geoserver/webapps/geoserver/WEB-INF/lib
SUB_FILES=	pkg-message
PLIST_FILES=	${GSLIBDIR}/gt-jdbc-mysql-2.7.2.jar \
		${GSLIBDIR}/mysql-connector-java-5.1.5.jar

LICENSE=	LGPL21

NO_STAGE=	yes
do-install:
		@${MKDIR} ${PREFIX}/${GSLIBDIR}
.for f in ${PLIST_FILES:S,^${GSLIBDIR}/,,}
		${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${GSLIBDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
