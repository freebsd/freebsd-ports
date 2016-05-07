# Created by: Matthew Seaman
# $FreeBSD$


PORTNAME=	mysql-connector-java
PORTVERSION=	5.1.38
CATEGORIES=	databases java
MASTER_SITES=	MYSQL/Connector-J

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	MySQL Connector/J: JDBC interface for MySQL

LICENSE=	GPLv2

RUN_DEPENDS=	${JAVALIBDIR}/log4j.jar:devel/log4j

USES=		cpe
CPE_VENDOR=	oracle
CPE_PRODUCT=	mysql_connector_j

USE_JAVA=	yes
JAVA_VERSION=	1.6 1.7
BUILDDIR=	${WRKDIR}/${DISTNAME}
APIDOCSDIR=	${STAGEDIR}${DOCSDIR}/javadoc
SRCDIR=		${WRKDIR}/${DISTNAME}/src
JAVADOCDIR=	${WRKDIR}/${DISTNAME}/javadoc
DESTJARFILE=	${PORTNAME}.jar
EXTRADOCS=	CHANGES docs/connector-j.html docs/connector-j.pdf
JARFILE=	${DISTNAME}-bin.jar
JDCLASSPATH=	${SRCDIR}:${CLASSPATH}

PLIST_FILES=	${JAVAJARDIR}/${DESTJARFILE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

do-build:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${JAVADOCDIR} && (cd ${SRCDIR};               \
	    ${JAVADOC} -quiet -breakiterator -encoding utf8     \
	    -d ${JAVADOCDIR} -package -classpath ${JDCLASSPATH}	\
	    com.mysql.jdbc org.gjt.mm.mysql)
.endif

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${ECHO_MSG} -n ">> Installing .jar files..."
	@${INSTALL_DATA} ${BUILDDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

do-install-apidocs:
.if ${PORT_OPTIONS:MDOCS}
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
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/$$extradoc ${STAGEDIR}${DOCSDIR} ; \
	done
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
