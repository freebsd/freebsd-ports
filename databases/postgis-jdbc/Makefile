# New ports collection makefile for:	postgis-jdbc
# Date created:			June 25 2004
# Whom:				Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	postgis-jdbc
PORTVERSION=	0.8.2
CATEGORIES=	databases java
MASTER_SITES=	http://postgis.refractions.net/
DISTNAME=	postgis-${PORTVERSION}

MAINTAINER=	boris@brooknet.com.au
COMMENT=	PostGIS spatial data structures for JDBC

BUILD_DEPENDS=	${JAVAJARDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc

USE_JAVA=	1.4+
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
MAKE_ARGS=	EXAMPLESDIR="${EXAMPLESDIR}" \
		DESTDIR="${PREFIX}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		JAVAJARDIR="${JAVAJARDIR}" \
		JAVAC="${JAVAC}" \
		JAVA="${JAVA}" \
		JAR="${JAR}"

WRKSRC=		${WRKDIR}/postgis-${PORTVERSION}/jdbc

.include <bsd.port.mk>
