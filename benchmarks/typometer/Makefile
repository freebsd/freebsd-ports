# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	typometer
PORTVERSION=	1.0
DISTVERSIONSUFFIX=	-bin
CATEGORIES=	benchmarks java
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Text/code editor typing latency analyzer

LICENSE=	GPLv3

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
	${PRINTF} "!#/bin/sh\n\n%s %s\n" "${JAVA} -jar" \
		"${PREFIX}/bin/${PORTNAME}-${PORTVERSION}.jar" \
			> ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
