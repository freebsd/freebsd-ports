PORTNAME=	gflags
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++
WWW=		https://github.com/gflags/gflags

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake:testing compiler:c++11-lang pathfix shebangfix

CMAKE_ARGS=	-DGFLAGS_NAMESPACE:STRING=gflags
CMAKE_OFF=	BUILD_TESTING \
		REGISTER_INSTALL_PREFIX
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		EXPORT_NAMESPACE_SET \
		EXPORT_NONAMESPACE_SET \
		INSTALL_HEADERS \
		INSTALL_SHARED_LIBS \
		INSTALL_STATIC_LIBS
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

SHEBANG_FILES=	src/gflags_completions.sh

post-install:
	${LN} -s libgflags.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgflags.so.${PORTVERSION:R:R}
	${LN} -s libgflags_nothreads.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libgflags_nothreads.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
