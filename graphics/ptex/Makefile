PORTNAME=	ptex
PORTREVISION=	2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.2
CATEGORIES?=	graphics

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Per face texture library

LICENSE=	BSD3CLAUSE

USES=		cmake:insource compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wdas

# yes really, the release tarbal doesn't know what version it is
CMAKE_ARGS+=	-DPTEX_VER:STRING=${DISTVERSION}

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

post-build-DOCS-on:
	@(cd ${WRKSRC}/src/doc && doxygen Doxyfile)

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/ptex/libPtex.so \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/ptex/libPtex.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/utils/ptxinfo \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${PREFIX}/include/ptex
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/ptex/*.h ${STAGEDIR}/${PREFIX}/include/ptex

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${BUILD_WRKSRC}/src/doc/ptex/ && \
		${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
