# New ports collection makefile for:   mx4j
# Date created:                16 Jan 2005
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	mx4j
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/MX4J%20Binary/${PORTVERSION}

MAINTAINER=	simon@olofsson.de
COMMENT=	Open Source implementation of the Java Management Extensions (JMX)

USE_JAVA=	yes
JAVA_VERSION=	1.3+

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

JARFILES=	mx4j-examples.jar mx4j-impl.jar mx4j-jmx.jar \
		mx4j-remote.jar mx4j-rimpl.jar mx4j-rjmx.jar \
		mx4j-soap.war mx4j-tools.jar mx4j.jar

PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}
NO_BUILD=	yes

do-install: do-install-jar do-install-javadoc

do-install-jar:
	@${ECHO_MSG} -n ">> Installing .jar files in ${JAVAJARDIR} ..."
	@for jarfile in ${JARFILES}; do					\
		${INSTALL_DATA} ${WRKSRC}/lib/$$jarfile ${JAVAJARDIR} ;	\
	done
	@${ECHO_MSG} " [DONE]"

do-install-javadoc:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR} ..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -n ">> Installing examples in ${EXAMPLESDIR} ..."
	@cd ${WRKSRC}/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
