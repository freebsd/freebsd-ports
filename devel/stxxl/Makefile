PORTNAME=	stxxl
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standard Template Library for Extra Large Data Sets
WWW=		https://stxxl.org/ \
		https://github.com/stxxl/stxxl

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake
CMAKE_OFF=	USE_GNU_PARALLEL  # may be enabled for future versions of clang with openmp support

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS CHANGELOG README TODO ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
