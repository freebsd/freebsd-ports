# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	databases java
PKGNAMESUFFIX=	-jdbc

MAINTAINER=	girgen@pingpong.net
COMMENT=	The Java JDBC implementation for PostgreSQL

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>

CONFIGURE_ARGS=	--with-java

USE_JAVA=	1.1+

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
MAKE_ENV+=	JAVA_HOME="${JAVA_HOME}"
MAKE_ARGS+=	-C src/interfaces/jdbc

post-install:
	@ ${MKDIR} -m 0555 ${PREFIX}/share/java/classes ;\
	  ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/jars/postgresql.jar \
			  ${PREFIX}/share/java/classes/postgresql.jar
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -m 0555 ${EXAMPLESDIR} ;\
	  cd ${WRKSRC}/src/interfaces/jdbc/example ;\
	  ${PAX} -rw . ${EXAMPLESDIR}
.for i in README
	@ ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/$i \
			  ${EXAMPLESDIR}
.endfor
.endif
	@ ${ECHO} ==================================== ;\
	  ${SED} -e "s,/usr/local,${PREFIX},g"  ${PKGDIR}/pkg-message ;\
	  ${ECHO} ====================================

.include <bsd.port.mk>
