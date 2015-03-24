# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.1.1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD3CLAUSE

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON -DBUILD_TESTING=ON
USE_LDCONFIG=	yes
USES=		cmake shebangfix

GH_ACCOUNT=	schuhschuh
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
USE_GITHUB=	yes

SHEBANG_FILES=	src/gflags_completions.sh

post-install:
	${LN} -s libgflags.so ${STAGEDIR}${PREFIX}/lib/libgflags.so.2
	${LN} -s libgflags_nothreads.so ${STAGEDIR}${PREFIX}/lib/libgflags_nothreads.so.2

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>
