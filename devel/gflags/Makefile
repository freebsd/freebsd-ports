# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_STATIC_LIBS=ON \
		-DBUILD_TESTING=ON \
		-DGFLAGS_NAMESPACE:STRING=gflags \
		-DINSTALL_HEADERS=ON \
		-DINSTALL_SHARED_LIBS=ON \
		-DINSTALL_STATIC_LIBS=ON \
		-DREGISTER_INSTALL_PREFIX=OFF
TEST_TARGET=	test
USE_LDCONFIG=	yes
USES=		cmake pathfix shebangfix

USE_GITHUB=	yes

SHEBANG_FILES=	src/gflags_completions.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${MV} ${STAGEDIR}${PREFIX}/bin/gflags_completions.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/

.include <bsd.port.mk>
