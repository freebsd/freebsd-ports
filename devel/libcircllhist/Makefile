PORTNAME=	libcircllhist
PORTVERSION=	g20221215
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Circonus log-linear histogram C implementation
WWW=		https://github.com/circonus-labs/libcircllhist

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake lua:51,env shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	openhistogram
GH_TAGNAME=	95f8f6b089fc4e8dc215ed903221f9f55d4813b3
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/test/runTest.sh

GNU_CONFIGURE=	yes
ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_ALL_TARGET=	docs

post-install:
	${LN} -s libcircllhist.so.0.0.1 \
		${STAGEDIR}${PREFIX}/lib/libcircllhist.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/circllhist_print
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcircllhist.so.0.0.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
