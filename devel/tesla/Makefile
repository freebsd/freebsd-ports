# $FreeBSD$

PORTNAME=	tesla
DISTVERSION=	0.0.20140425
CATEGORIES=	devel lang

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Temporally Enhanced Security Logic Assertions

USES=		cmake:outsource ninja

BUILD_DEPENDS=	clang33:${PORTSDIR}/lang/clang33
RUN_DEPENDS=	clang33:${PORTSDIR}/lang/clang33
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libprotobuf.so:${PORTSDIR}/devel/protobuf

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

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} < 1000000
BROKEN=	does not build on 8 and 9
.endif

.include <bsd.port.post.mk>
