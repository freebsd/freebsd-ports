PORTNAME=	osmosis
PORTVERSION=	0.49.0
CATEGORIES=	astro java
MASTER_SITES=	https://github.com/openstreetmap/osmosis/releases/download/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line Java app for processing OpenStreetMap data
WWW=		https://wiki.openstreetmap.org/wiki/Osmosis

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		tar
USE_JAVA=	yes
JAVA_VERSION=	17+
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|; s|%%JAVA%%|${JAVA}|' \
		${WRKSRC}/bin/osmosis

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "script lib" ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/osmosis ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

do-test:
	@${STAGEDIR}${PREFIX}/bin/osmosis \
		--read-xml ${FILESDIR}/test.osm \
		--tf accept-ways highway='*' \
		--used-node \
		--write-xml ${WRKDIR}/test-out.osm
	${TEST} -s ${WRKDIR}/test-out.osm

.include <bsd.port.mk>
