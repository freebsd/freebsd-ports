PORTNAME=	shellbench
PORTVERSION=	20200806
CATEGORIES=	benchmarks

MAINTAINER=	se@FreeBSD.org
COMMENT=	Benchmark utility for POSIX shell comparison

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	shellspec
GH_TAGNAME=	ce43ba49d3

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
		${REINPLACE_CMD} 's:%%DATADIR%%:${DATADIR}:g' ${WRKSRC}/shellbench
		${REINPLACE_CMD} 's:%%DOCSDIR%%:${DOCSDIR}:g' ${WRKSRC}/shellbench
		${INSTALL_SCRIPT} ${WRKSRC}/shellbench ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${DATADIR}/
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
