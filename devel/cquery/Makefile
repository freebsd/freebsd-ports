# $FreeBSD$

PORTNAME=	cquery
PORTVERSION=	20180302
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Highly-scalable, low-latency language server for C/C++/Objective-C

LICENSE=	MIT

BROKEN_powerpc64=	fails to build: Checking for 'clang++' (C++ compiler): not found

BUILD_DEPENDS=	llvm-config60:devel/llvm60
LIB_DEPENDS=	libclang.so:devel/llvm60

USES=		compiler:c++14-lang waf

USE_GITHUB=	yes
GH_ACCOUNT=	cquery-project
GH_TUPLE=	miloyip:rapidjson:daabb88:rapidjson/third_party/rapidjson \
		onqtam:doctest:b40b7e7:doctest/third_party/doctest \
		greg7mdp:sparsepp:1ca7189:sparsepp/third_party/sparsepp \
		msgpack:msgpack-c:208595b:msgpack/third_party/msgpack-c \
		emilk:loguru:2c35b5e:loguru/third_party/loguru

PLIST_FILES=	bin/cquery

CONFIGURE_ARGS=	--variant=system --llvm-config=${LOCALBASE}/bin/llvm-config60
MAKE_ARGS=	--variant=system

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cquery

.include <bsd.port.mk>
