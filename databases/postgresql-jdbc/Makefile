# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	databases java
PKGNAMESUFFIX=	-jdbc

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The Java JDBC implementation for PostgreSQL

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

MASTERDIR=	${.CURDIR}/../../databases/postgresql74-server

CONFLICTS=	${PORTNAME}${PKGNAMESUFFIX}-7.[0-3]* \
		${PORTNAME}${PKGNAMESUFFIX}-[1-689]*

CONFIGURE_ARGS=	--with-java

USE_JAVA=	yes
JAVA_VERSION?=	"1.1+"

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
MAKE_ENV+=	JAVA_HOME="${JAVA_HOME}"
BUILD_DIRS=	src/interfaces/jdbc
SLAVE_ONLY=	yes

post-install:
	@- ${MKDIR} -m 0555 ${PREFIX}/share/java/classes ;\
	  ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/jars/postgresql.jar \
			  ${PREFIX}/share/java/classes/postgresql.jar
.if !defined(NOPORTDOCS)
	@- ${MKDIR} -m 0555 ${EXAMPLESDIR} ;\
	  cd ${WRKSRC}/src/interfaces/jdbc/example ;\
	  ${PAX} -rw . ${EXAMPLESDIR}
.for i in README
	@- ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/$i \
			  ${EXAMPLESDIR}
.endfor
.endif

.include "${MASTERDIR}/Makefile"
