# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	jmf
PORTVERSION=	2.1.1e
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	#http://java.sun.com/products/java-media/jmf/2.1.1/download.html
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-alljava

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Media Framework

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/JMF-${PORTVERSION}

RESTRICTED=	Redistribution of pre-compiled binaries is not permitted

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Check for JMF sources
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	because of licensing restrictions, you must fetch the source\
distribution manually.\
Please access: http://java.sun.com/products/java-media/jmf/2.1.1/download.html\
with a web browser and follow the "Download JMF ${PORTVERSION}" link.\
Select download format: cross-platform format.  Please place this file in\
${DISTDIR}
.endif

do-configure:
	for file in `${LS} ${WRKSRC}/bin/jm*`; do \
		${REINPLACE_CMD} -e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:g" -e "s:%%PREFIX%%:${PREFIX}:g" $${file}; \
	done
	@${FIND} ${WRKSRC}/bin -type f \( -name '*.bak' -o -name '*.orig' \) -delete

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/jm* ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${WRKSRC}/lib/jmf.properties \
		${JAVAJARDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
