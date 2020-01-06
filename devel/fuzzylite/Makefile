# $FreeBSD$

PORTNAME=	fuzzylite
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Fuzzy logic control library in C++

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	FL_BUILD_STATIC FL_BUILD_TESTS
CMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}
PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=varargs
.endif

.include <bsd.port.post.mk>
