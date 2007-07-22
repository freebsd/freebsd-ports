# New ports collection makefile for:	postgis-jdbc
# Date created:			June 25 2004
# Whom:				Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	postgis-jdbc
PORTVERSION=	1.2.1
CATEGORIES=	databases java geography
MASTER_SITES=	http://postgis.refractions.net/download/
DISTNAME=	postgis-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostGIS spatial data structures for JDBC

BUILD_DEPENDS=	${JAVALIBDIR}/jts.jar:${PORTSDIR}/math/jts	\
		${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc
RUN_DEPENDS=	${JAVALIBDIR}/jts.jar:${PORTSDIR}/math/jts	\
		${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_GMAKE=	yes
MAKE_ARGS=	EXAMPLESDIR="${EXAMPLESDIR}" \
		DESTDIR="${JAVAJARDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		JAVAC="${JAVAC}" \
		JAVA="${JAVA}" \
		JAR="${JAR}" \
		CLASSPATH="${JAVALIBDIR}/postgresql.jar:${JAVALIBDIR}/jts.jar" \
		mkinstalldirs="${MKDIR}"

WRKSRC=		${WRKDIR}/${DISTNAME}/java/jdbc

PORTDOCS=	README

do-install:
	${INSTALL_DATA} ${WRKSRC}/postgis.jar ${WRKSRC}/postgis_debug.jar	\
		${JAVAJARDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
