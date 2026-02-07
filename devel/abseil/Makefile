PORTNAME=	abseil
PORTVERSION=	20250127.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/abseil/abseil-cpp/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-cpp-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Abseil Common Libraries (C++)
WWW=		https://abseil.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang pathfix
CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DCMAKE_CXX_STANDARD=17 # force the same highest C++ standard because of ABI differences: see https://github.com/abseil/abseil-cpp/issues/819
PATHFIX_CMAKELISTSTXT=	AbseilHelpers.cmake

_GET_SOVER=	${GREP} ABSL_SOVERSION ${WRKSRC}/CMakeLists.txt \
		2>/dev/null | ${CUT} -d\" -f2
PLIST_SUB+=	LIBSUFX=${_GET_SOVER:sh}

.include <bsd.port.mk>
