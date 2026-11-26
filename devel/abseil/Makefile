PORTNAME=	abseil
PORTVERSION=	20250127.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/abseil/abseil-cpp/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-cpp-${PORTVERSION}

PATCH_SITES=	https://github.com/abseil/abseil-cpp/commit/
PATCHFILES+=	a4950fba03217d0ea102c98ce795c189bba50383.patch:-p1 # https://github.com/llvm/llvm-project/pull/138835
PATCHFILES+=	a9c2ffe882bbd903b296fe497462970602de4c21.patch:-p1 # https://github.com/abseil/abseil-cpp/pull/2213

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Abseil Common Libraries (C++)
WWW=		https://abseil.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang cpe pathfix
CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DCMAKE_CXX_STANDARD=17 # force the same highest C++ standard because of ABI differences: see https://github.com/abseil/abseil-cpp/issues/819
PATHFIX_CMAKELISTSTXT=	AbseilHelpers.cmake

CPE_VENDOR=	${PORTNAME:tl}
CPE_PRODUCT=	common_libraries

_GET_SOVER=	${GREP} ABSL_SOVERSION ${WRKSRC}/CMakeLists.txt \
		2>/dev/null | ${CUT} -d\" -f2
PLIST_SUB+=	LIBSUFX=${_GET_SOVER:sh}

.include <bsd.port.mk>
