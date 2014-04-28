# $FreeBSD$

PORTNAME=	tesla
DISTVERSION=	0.0.20140425
CATEGORIES=	devel lang

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Temporally Enhanced Security Logic Assertions

USES=		cmake:outsource ninja

BUILD_DEPENDS=	clang33:${PORTSDIR}/lang/clang33
RUN_DEPENDS=	clang33:${PORTSDIR}/lang/clang33
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		protobuf:${PORTSDIR}/devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-TESLA
GH_PROJECT=	TESLA
GH_TAGNAME=	3136f0f
GH_COMMIT=	3136f0f

CC=		clang33
CXX=		clang++33

CMAKE_ARGS+=	-DCMAKE_LLVM_CONFIG=llvm-config33

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${WRKSRC}/build

.include <bsd.port.mk>
