# New ports collection makefile for:	mysql-connector-java
# Date created:		8 October 2003
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-java
PORTVERSION=	3.1.6
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-J

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	MySQL Connector/J: JDBC interface for MySQL

RUN_DEPENDS=	${LOCALBASE}/share/java/classes/log4j.jar:${PORTSDIR}/devel/log4j

.if !defined(WITHOUT_COMPILE)

BUILD_DEPENDS=	${LOCALBASE}/share/java/classes/junit.jar:${PORTSDIR}/java/junit \
		${LOCALBASE}/share/java/classes/log4j.jar:${PORTSDIR}/devel/log4j

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.4+
ALL_TARGET=	clean compile-driver
BUILDDIR=	${WRKDIR}/build-mysql-jdbc/${DISTNAME}

.else

USE_JAVA=	yes
JAVA_VERSION=	1.2+
BUILDDIR=	${WRKDIR}/${DISTNAME}

.endif

APIDOCSDIR=	${DOCSDIR}/javadoc
DESTJARFILE=	${PORTNAME}.jar
EXTRAJARS=	jdbc2_0-stdext.jar jta-spec1_0_1.jar
EXTRADOCS=	README CHANGES
JARFILE=	${DISTNAME}-bin.jar
JDCLASSPATH=	${WRKSRC}:${WRKSRC}/lib/jdbc2_0-stdext.jar:${WRKSRC}/lib/jta-spec1_0_1.jar:${CLASSPATH}

PLIST_FILES=	share/java/classes/jdbc2_0-stdext.jar \
		share/java/classes/jta-spec1_0_1.jar \
		share/java/classes/mysql-connector-java.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port requires JDK 1.4.x or better to compile, but the"
	@${ECHO_MSG} "JDBC driver will operate with JVM 1.2.x or better"
	@${ECHO_MSG} ""

.if !defined(WITHOUT_COMPILE)
post-build:
.else
do-build:
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${BUILDDIR}/doc && (cd ${BUILD_WRKSRC};  \
	    ${JAVADOC} -d ${BUILDDIR}/doc -package         \
	        -classpath  ${JDCLASSPATH}                 \
	         com.mysql.jdbc org.gjt.mm.mysql)
.endif

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${ECHO_CMD} -n ">> Installing .jar files..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${BUILDDIR}/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@for extrajar in ${EXTRAJARS} ; do                                 \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/lib/$$extrajar ${JAVAJARDIR} ; \
	done
	@${ECHO_CMD} " [ DONE ]"

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${APIDOCSDIR}
	@${CP} -r ${BUILDDIR}/doc/* ${APIDOCSDIR}
	@for extradoc in ${EXTRADOCS} ; do                    \
	  ${INSTALL_DATA} ${BUILDDIR}/$$extradoc ${DOCSDIR} ; \
	done
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
