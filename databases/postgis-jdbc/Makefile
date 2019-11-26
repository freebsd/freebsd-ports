# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	postgis-jdbc
PORTVERSION=	2.1.7
CATEGORIES=	databases java geography
MASTER_SITES=	http://postgis.net/stuff/
EXTRACT_SUFX=	.jar

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	PostGIS spatial data structures for JDBC

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

USES=		zip:infozip
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/postgis-jdbc-2.1.7.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
