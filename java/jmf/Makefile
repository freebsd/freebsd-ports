# Created by: Anton Yudin <toha@toha.org.ua>

PORTNAME=	jmf
PORTVERSION=	2.1.1e
PORTREVISION=	3
CATEGORIES=	java multimedia
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-alljava

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Media Framework

# Converted from RESTRICTED
LICENSE=	jmf
LICENSE_NAME=	jmf
LICENSE_TEXT=	Redistribution of pre-compiled binaries is not permitted
LICENSE_PERMS=	auto-accept

USES=		zip
USE_JAVA=	yes
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/JMF-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.pre.mk>

# Check for JMF sources
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	because of licensing restrictions, you must fetch the source\
distribution manually.\
Please access https://www.oracle.com/java/technologies/java-archive-downloads-java-client-downloads.html \
with a web browser and follow the "Java Media Framework (JMF) ${PORTVERSION}" link.\
Select download format: cross-platform format.  Please place this file in\
${DISTDIR}
.endif

do-configure:
	for file in `${LS} ${WRKSRC}/bin/jm*`; do \
		${REINPLACE_CMD} -e "s:%%JAVAJARDIR%%:${JAVAJARDIR}:g" -e "s:%%PREFIX%%:${PREFIX}:g" $${file}; \
	done
	@${FIND} ${WRKSRC}/bin -type f \( -name '*.bak' -o -name '*.orig' \) -delete

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/jm* ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${WRKSRC}/lib/jmf.properties \
		${STAGEDIR}${JAVAJARDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
