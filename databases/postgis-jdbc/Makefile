# New ports collection makefile for:	postgis-jdbc
# Date created:			June 25 2004
# Whom:				Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	postgis-jdbc
PORTVERSION=	1.0.0r3
CATEGORIES=	databases java
MASTER_SITES=	http://postgis.refractions.net/
DISTNAME=	postgis-1.0.0-rc3

MAINTAINER=	boris@brooknet.com.au
COMMENT=	PostGIS spatial data structures for JDBC

BUILD_DEPENDS=	${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc

USE_JAVA=	yes
JAVA_VERSION=	1.4+
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
USE_GMAKE=	yes
MAKE_ARGS=	EXAMPLESDIR="${EXAMPLESDIR}" \
		DESTDIR="${JAVAJARDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		JAVAC="${JAVAC}" \
		JAVA="${JAVA}" \
		JAR="${JAR}" \
		CLASSPATH="${JAVALIBDIR}/postgresql.jar" \
		mkinstalldirs="${MKDIR}"

WRKSRC=		${WRKDIR}/${DISTNAME}/jdbc2

do-install:
		${INSTALL_DATA} ${WRKSRC}/postgis.jar ${JAVAJARDIR}
		${MKDIR} ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/src/examples/* ${EXAMPLESDIR}/

.include <bsd.port.mk>
