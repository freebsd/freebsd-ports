# Ports collection makefile for:	Jaxen
# Date created:				9 Decemeber 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	jaxen
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-FCS

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	Java XPath Engine

USE_JAVA=	1.3+
NO_BUILD=	YES

JARFILES=	jaxen-core.jar jaxen-dom.jar jaxen-dom4j.jar jaxen-exml.jar jaxen-full.jar jaxen-jdom.jar lib/saxpath.jar
WRKDOCSDIR=	${WRKSRC}/doc
PLIST_FILES+=	${JARFILES:S,^lib/,,:S,^,%%JAVAJARDIR%%/,}

.if !defined(NOPORTDOCS)
DOCS=		default.css download.html faq.html index.html javadoc status.html style
PORTDOCS=	LICENSE ${DOCS}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}
	@${ECHO_MSG} -n " ${JARFILE:S,^lib/,,}"
.endfor
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKDOCSDIR} && ${FIND} ${DOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKDOCSDIR} && ${FIND} ${DOCS} -type f -exec ${INSTALL_DATA} ${WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
