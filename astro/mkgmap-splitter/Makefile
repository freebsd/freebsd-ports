PORTNAME=	splitter
PORTVERSION=	r647
CATEGORIES=	astro converters java
MASTER_SITES=	https://www.mkgmap.org.uk/download/
PKGNAMEPREFIX=	mkgmap-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tile splitter for mkgmap

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA="${JAVA}"

PLIST_FILES=	bin/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${DATADIR}/lib/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/intro.txt ${STAGEDIR}${DOCSDIR}/

do-test:
	${JAVA} -jar ${WRKSRC}/${PORTNAME}.jar --help >/dev/null 2>&1

.include <bsd.port.mk>
