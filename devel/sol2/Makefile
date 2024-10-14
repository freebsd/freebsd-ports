PORTNAME=	sol2
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0-alpha
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library binding to Lua
WWW=		https://github.com/ThePhD/sol2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++17-lang lua:run

USE_GITHUB=	yes
GH_ACCOUNT=	ThePhD

CMAKE_TESTING_ON=	SOL2_TESTS

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && \
	${COMPILER_VERSION} >= 180 && ${COMPILER_VERSION} < 190
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-include_sol_function__types__stateless.hpp
.endif

.include <bsd.port.post.mk>
