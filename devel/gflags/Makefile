# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.2.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake compiler:c++11-lang pathfix shebangfix

CMAKE_ARGS=	-DGFLAGS_NAMESPACE:STRING=gflags
CMAKE_OFF=	REGISTER_INSTALL_PREFIX
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS BUILD_TESTING \
		INSTALL_HEADERS INSTALL_SHARED_LIBS INSTALL_STATIC_LIBS
TEST_TARGET=	test
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

SHEBANG_FILES=	src/gflags_completions.sh

post-install:
	${LN} -s libgflags.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgflags.so.${PORTVERSION:R:R}
	${LN} -s libgflags_nothreads.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgflags_nothreads.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
