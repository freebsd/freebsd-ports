# Ports collection makefile for:	Jaxen
# Date created:				9 Decemeber 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	jaxen
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	java textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1-0-FCS
DISTNAME=	${PORTNAME}-${PORTVERSION}-FCS

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java XPath Engine

USE_JAVA=	YES
JAVA_VERSION=	1.3+
NO_BUILD=	YES

JARFILES=	jaxen-core.jar jaxen-dom.jar jaxen-dom4j.jar jaxen-exml.jar jaxen-full.jar jaxen-jdom.jar lib/saxpath.jar
PLIST_FILES+=	${JARFILES:S,^lib/,,:S,^,%%JAVAJARDIR%%/,}

.if !defined(NOPORTDOCS)
DOCS=		default.css download.html faq.html index.html javadoc status.html style
PORTDOCS=	LICENSE ${DOCS}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${JARFILES} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} ${DOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
