# Created by: gahr
# $FreeBSD$

PORTNAME=	gervill
PORTVERSION=	1.0
CATEGORIES=	audio java
MASTER_SITES=	SF/rasmusdsp/${PORTNAME}/Gervill%20${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Generic sound synthesizer for Java

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	jar
JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadocs
.endif

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/javadocs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
