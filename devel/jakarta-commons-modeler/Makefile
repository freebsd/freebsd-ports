# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-modeler
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_BINARIES}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mechanisms to create Model MBeans compatible with JMX specification

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/docs \
	 && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/docs/{} \; \
	 && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/docs/{} \;
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.txt ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
