# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	geoserver
PORTVERSION=	2.12.1
CATEGORIES=	databases geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}/extensions
PKGNAMESUFFIX=	-mysql-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL DataStore implementation for GeoServer

LICENSE=	LGPL21

RUN_DEPENDS=	${LOCALBASE}/geoserver/start.jar:graphics/geoserver

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

GSLIBDIR=	geoserver/webapps/geoserver/WEB-INF/lib
SUB_FILES=	pkg-message
PLIST_FILES=	${GSLIBDIR}/gt-jdbc-mysql-18.1.jar \
		${GSLIBDIR}/mysql-connector-java-5.1.17.jar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GSLIBDIR}
.for f in ${PLIST_FILES:S,^${GSLIBDIR}/,,}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/${GSLIBDIR}
.endfor

.include <bsd.port.mk>
