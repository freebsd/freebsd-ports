# $FreeBSD$

PORTNAME=	fuzzylite
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0
CATEGORIES=	devel

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Fuzzy logic control library in C++

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: unrecognized command line option "-Wno-type-limits"

USES=		cmake compiler
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFL_BUILD_STATIC:BOOL=OFF \
		-DFL_BUILD_TESTS:BOOL=OFF
CMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}
PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 39
CFLAGS+=	-Wno-error=varargs
.endif

.include <bsd.port.post.mk>
