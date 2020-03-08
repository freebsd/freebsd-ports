# $FreeBSD$

PORTNAME=	cquery
PORTVERSION=	20180718
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Highly-scalable, low-latency language server for C/C++/Objective-C

LICENSE=	MIT

LIB_DEPENDS=	libclang.so:devel/llvm${LLVM_DEFAULT}

USES=		compiler:c++14-lang cmake

USE_GITHUB=	yes
GH_ACCOUNT=	cquery-project
GH_TUPLE=	miloyip:rapidjson:daabb88:rapidjson/third_party/rapidjson \
		onqtam:doctest:b40b7e7:doctest/third_party/doctest \
		greg7mdp:sparsepp:1ca7189:sparsepp/third_party/sparsepp \
		msgpack:msgpack-c:208595b:msgpack/third_party/msgpack-c \
		emilk:loguru:6bf94c:loguru/third_party/loguru \
		zeux:pugixml:24a7064:pugixml/third_party/pugixml

PLIST_FILES=	bin/cquery

CMAKE_ON=	SYSTEM_CLANG
CMAKE_ARGS=	-DCLANG_ROOT=${LOCALBASE}/llvm${LLVM_DEFAULT}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cquery

.include <bsd.port.mk>
