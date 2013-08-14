# $FreeBSD$

PORTNAME=	ccons
PORTVERSION=	r243
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Interactive Console for the C Programming Language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/llvm-config:${PORTSDIR}/devel/llvm \
		${LOCALBASE}/bin/clang:${PORTSDIR}/lang/clang \
		${LOCALBASE}/bin/ld:${PORTSDIR}/devel/binutils
LIB_DEPENDS=	ncurses:${PORTSDIR}/devel/ncurses

ONLY_FOR_ARCHS=	i386 amd64
USES=		cmake
CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/llvm-config

CXX=	${LOCALBASE}/bin/clang++
CXXFLAGS+=	-fno-rtti
LDFLAGS+=	-lclangFrontendTool -lclangFrontend -lclangDriver -lclangSerialization \
		-lclangCodeGen -lclangParse -lclangSema -lclangStaticAnalyzerCheckers \
		-lclangStaticAnalyzerCore -lclangAnalysis -lclang -lclangAST -lclangLex \
		-lclangBasic -ledit -lm

PLIST_FILES=	bin/ccons

WRKSRC=	${WRKDIR}/ccons


MAN1=	ccons.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900044
BROKEN=	ccons does not work on FreeBSD < 9.0-RELEASE
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccons ${PREFIX}/bin/ccons
	@${INSTALL_MAN} ${WRKSRC}/man/ccons.1 ${MAN1PREFIX}/man/man1/ccons.1

.include <bsd.port.post.mk>
