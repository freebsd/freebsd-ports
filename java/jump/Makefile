PORTNAME=	jump
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	java math
MASTER_SITES=	SF/${PORTNAME}-math/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library for arbitrary precision computations
WWW=		https://jump-math.sourceforge.net/

USES=		java:ant,run

ALL_TARGET=	jar

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	apidocs

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${STAGEDIR}${JAVAJARDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/apidocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
