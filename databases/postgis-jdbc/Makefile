# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	postgis-jdbc
PORTVERSION=	1.4.0
CATEGORIES=	databases java geography
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
DISTFILES=	postgis_${PORTVERSION}.jar

MAINTAINER=	wenheping@gmail.com
COMMENT=	PostGIS spatial data structures for JDBC

BROKEN=		unfetchable

RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/postgis_1.4.0.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}postgis_${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
