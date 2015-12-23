# Created by: ijliao
# $FreeBSD$

PORTNAME=	jmusic
PORTVERSION=	1.6.4
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/jMusic_Stable/${PORTVERSION} \
		SF/${PORTNAME}/jMusic_Instruments/${PORTVERSION:S/.4//}/:instruments \
		SF/${PORTNAME}/jMusic_Docs/${PORTVERSION}/:docs
DISTFILES=	jMusic${PORTVERSION}.jar \
		jMusic_1.6_inst.zip:instruments \
		jMusic_doc_${PORTVERSION}.zip:docs
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	jMusic_1.6_inst.zip \
		jMusic_doc_${PORTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Composition in Java

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jMusic${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} inst ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
