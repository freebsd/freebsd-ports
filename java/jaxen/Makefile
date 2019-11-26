# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	jaxen
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	java textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1-0-FCS
DISTNAME=	${PORTNAME}-${PORTVERSION}-FCS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java XPath Engine

USE_JAVA=	YES
NO_BUILD=	YES

JARFILES=	jaxen-core.jar jaxen-dom.jar jaxen-dom4j.jar jaxen-exml.jar jaxen-full.jar jaxen-jdom.jar lib/saxpath.jar
PLIST_FILES+=	${JARFILES:S,^lib/,,:S,^,%%JAVAJARDIR%%/,}

DOCS=		default.css download.html faq.html index.html javadoc status.html style
PORTDOCS=	LICENSE ${DOCS}

OPTIONS_DEFINE=	DOCS

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${JARFILES} ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} ${DOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}/LICENSE
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
