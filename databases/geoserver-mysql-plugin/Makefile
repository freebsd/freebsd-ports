# New ports collection makefile for:	geoserver-mysql-plugin
# Date created:				08 March 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	geoserver
PORTVERSION=	1.7.4
CATEGORIES=	databases geography java
MASTER_SITES=	SF
PKGNAMESUFFIX=	-mysql-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A MySQL DataStore implementation for GeoServer

RUN_DEPENDS=	${LOCALBASE}/geoserver/start.jar:${PORTSDIR}/graphics/geoserver

USE_ZIP=	yes
NO_BUILD=	yes

GSLIBDIR=	geoserver/webapps/geoserver/WEB-INF/lib
SUB_FILES=	pkg-message
PLIST_FILES=	${GSLIBDIR}/gt-mysql-2.5.5.jar \
		${GSLIBDIR}/mysql-connector-java-5.1.5.jar

do-install:
		@${MKDIR} ${PREFIX}/${GSLIBDIR}
.for f in ${PLIST_FILES:S,^${GSLIBDIR}/,,}
		${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${GSLIBDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
