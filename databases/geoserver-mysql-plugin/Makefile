PORTNAME=	geoserver
DISTVERSION=	2.25.2
CATEGORIES=	databases geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}/extensions
PKGNAMESUFFIX=	-mysql-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL DataStore implementation for GeoServer
WWW=		http://geoserver.org/display/GEOSDOC/MySQL+DataStore

LICENSE=	LGPL21

RUN_DEPENDS=	${LOCALBASE}/geoserver/start.jar:graphics/geoserver

USES=		cpe zip

CPE_VENDOR=	osgeo

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

GSLIBDIR=	geoserver/webapps/geoserver/WEB-INF/lib
PLIST_FILES=	${GSLIBDIR}/gt-jdbc-mysql-31.2.jar \
		${GSLIBDIR}/mysql-connector-java-8.0.28.jar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GSLIBDIR}
.for f in ${PLIST_FILES:S,^${GSLIBDIR}/,,}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/${GSLIBDIR}
.endfor

.include <bsd.port.mk>
