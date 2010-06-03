# New ports collection makefile for:	mysql-connector-java
# Date created:		8 October 2003
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-java
PORTVERSION=	5.1.12
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-J

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	MySQL Connector/J: JDBC interface for MySQL

RUN_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j

CONFLICTS=	mysql-connector-java*-5.0.*

USE_JAVA=	yes
JAVA_VERSION=	1.3+
BUILDDIR=	${WRKDIR}/${DISTNAME}
APIDOCSDIR=	${DOCSDIR}/javadoc
SRCDIR=		${WRKDIR}/${DISTNAME}/src
JAVADOCDIR=	${WRKDIR}/${DISTNAME}/javadoc
DESTJARFILE=	${PORTNAME}.jar
EXTRADOCS=	README CHANGES docs/connector-j.html docs/connector-j.pdf
JARFILE=	${DISTNAME}-bin.jar
JDCLASSPATH=	${SRCDIR}:${CLASSPATH}

PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-build:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${JAVADOCDIR} && (cd ${SRCDIR}; \
	    ${JAVADOC} -quiet -breakiterator      \
		-d ${JAVADOCDIR} -package         \
	        -classpath  ${JDCLASSPATH}        \
	         com.mysql.jdbc org.gjt.mm.mysql)
.endif

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${ECHO_MSG} -n ">> Installing .jar files..."
	@${INSTALL_DATA} ${BUILDDIR}/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${APIDOCSDIR}
	@cd ${JAVADOCDIR} && for src in $$( ${FIND} . ) ; do \
	    dst=${APIDOCSDIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
	        ${MKDIR} $$dst ; \
	    else \
	        ${INSTALL_DATA} $$src $$dst ; \
	    fi \
	done
	@for extradoc in ${EXTRADOCS} ; do                          \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/$$extradoc ${DOCSDIR} ; \
	done
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
