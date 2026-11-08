PORTNAME=	antlr4-cpp-runtime
PORTVERSION=	4.13.2
DISTVERSIONSUFFIX=	-source
CATEGORIES=	devel
MASTER_SITES=	https://www.antlr.org/download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ target for ANTLR 4
WWW=		https://www.antlr.org/ \
		https://github.com/antlr/antlr4/tree/dev/runtime/Cpp \
		https://github.com/antlr/antlr4

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++17-lang zip

CMAKE_OFF=	ANTLR_BUILD_CPP_TESTS \
		DISABLE_WARNINGS \
		TRACE_ATN \
		WITH_DEMO \
		WITH_STATIC_CRT
CMAKE_ON=	ANTLR_BUILD_SHARED \
		ANTLR_BUILD_STATIC \
		WITH_LIBCXX
NO_WRKSUBDIR=	yes

DOCSDIR=	${PREFIX}/share/doc/libantlr4
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/runtime/_deps/

.include <bsd.port.mk>
