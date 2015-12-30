# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DBUILD_STATIC_LIBS=ON \
		-DBUILD_TESTING=ON \
		-DGFLAGS_NAMESPACE=gflags
TEST_TARGET=	test
USE_LDCONFIG=	yes
USES=		cmake shebangfix

USE_GITHUB=	yes

SHEBANG_FILES=	src/gflags_completions.sh

.include <bsd.port.mk>
