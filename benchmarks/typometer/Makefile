PORTNAME=	typometer
PORTVERSION=	1.0.1
DISTVERSIONSUFFIX=	-bin
CATEGORIES=	benchmarks java
# Not USE_GITHUB because we want to grab the binary release (it's Java)
MASTER_SITES=	https://github.com/pavelfatin/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Text/code editor typing latency analyzer

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-${PORTVERSION}.jar
PORTDOCS=	README.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${PREFIX}/bin
	${PRINTF} "#!/bin/sh\n\n%s %s\n" "exec ${JAVA} -jar" \
		"${PREFIX}/bin/${PORTNAME}-${PORTVERSION}.jar" \
			> ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
