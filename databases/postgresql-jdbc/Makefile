# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql-jdbc
PORTVERSION=	7.2
CATEGORIES=	databases java

MAINTAINER=	girgen@partitur.se

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/jakarta-ant
# Since we cannot distribute JVMs in binary format yet, don't set this
# to allow bento to build something useful
#RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk13

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

CONFIGURE_ARGS=	--with-java

# Honour JAVA_HOME if it is set
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
MAKE_ENV+=	JAVA_HOME="${JAVA_HOME}"
MAKE_ARGS+=	-C src/interfaces/jdbc

pre-everything::
	@ ${ECHO} ;\
	  ${ECHO} "Building PostgreSQL JDBC using the JVM in ${JAVA_HOME}." ;\
	  ${ECHO} "You can instruct this port to use your favourite JVM by typing:" ;\
	  ${ECHO} "      make JAVA_HOME=${LOCALBASE}/jdk1.1.8" ;\
	  ${ECHO} "or similar." ;\
	  ${ECHO}

post-build:
# will fail for java 1.1, so ignore errors
	-@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C contrib/retep

post-install:
	@ ${MKDIR} -m 0555 ${PREFIX}/share/java/classes ;\
	  ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/jars/postgresql.jar \
			  ${PREFIX}/share/java/classes/postgresql.jar
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C contrib/retep install
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/examples/postgresql ;\
	  cd ${WRKSRC}/src/interfaces/jdbc/example ;\
	  pax -rw . ${PREFIX}/share/examples/postgresql
.for i in README Implementation
	@ ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/$i \
			  ${PREFIX}/share/examples/postgresql
.endfor
.endif
	@ ${ECHO} ==================================== ;\
	  ${SED} -e "s,/usr/local,${PREFIX},g" pkg-message ;\
	  ${ECHO} ====================================

.include <bsd.port.mk>
