# $FreeBSD$

PORTNAME=	ccls
DISTVERSION=	0.20190731
CATEGORIES=	devel
MASTER_SITES=	LOCAL/tobik

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	C/C++/ObjC language server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		rapidjson>=1.1.0_4:devel/rapidjson
LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++17-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	MaskRay
GH_TAGNAME=	8b0332173f51389d3ab914313b874cea04f4ead4

CMAKE_ARGS=	-DClang_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm"
CXXFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/ccls
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_MASTER_SITES=	LOCAL/tobik:docs \
			https://pkg.tobik.me/distfiles/:docs
DOCS_DISTFILES=		MaskRay-ccls.wiki-20190226.tar.gz:docs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ccls.wiki && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
