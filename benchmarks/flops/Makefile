PORTNAME=	flops
PORTVERSION=	2.2
CATEGORIES=	benchmarks

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Floating point benchmark to give your MFLOPS rating
WWW=		https://performance.netlib.org/performance/html/flops.html

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

PORTDOCS=	README
PLIST_FILES=	bin/flops

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flops ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
