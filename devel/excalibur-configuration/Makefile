# New ports collection makefile for:	excalibur-configuration
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	excalibur-configuration
PORTVERSION=	1.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	avalon/${PORTNAME}/binaries

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Configuration management extensions to the Avalon Framework

RUN_DEPENDS=	${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework

USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
PORTDOCS=	README.txt apidocs
.endif

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/apidocs/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/apidocs/{} \;
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
