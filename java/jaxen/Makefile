# Ports collection makefile for:	Jaxen
# Date created:				9 Decemeber 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	jaxen
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-FCS

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	Java XPath Engine

USE_JAVA=	1.3+
NO_BUILD=	YES

PORT_JARFILES=		jaxen-core.jar jaxen-dom.jar jaxen-dom4j.jar jaxen-exml.jar jaxen-full.jar jaxen-jdom.jar
JAVA_WRKDOCSDIR=	${WRKSRC}/doc
PLIST_FILES+=		${PORT_JARFILES:S,^,${JAVAJARDIR:S,^${PREFIX}/,,}/,}

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE default.css download.html faq.html index.html javadoc status.html style
.endif

do-install:
	@${ECHO} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${PORT_JARFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${JARFILE} ${JAVAJARDIR}
	@${ECHO} -n " ${JARFILE}"
.endfor
	@${ECHO} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
	@${ECHO} " [DONE]"
.endif

.include <bsd.port.mk>
