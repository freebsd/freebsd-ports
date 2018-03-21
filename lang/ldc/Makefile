# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldc
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ldc-developers/ldc/releases/download/v${PORTVERSION}/:source \
		https://github.com/ldc-developers/ldc/releases/download/v${BOOTVER}/:bootstrap
DISTFILES=	${DISTNAME:S/$/-src/}${EXTRACT_SUFX}:source

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The LLVM-based D compiler

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm40>0:devel/llvm40
RUN_DEPENDS=	llvm40>0:devel/llvm40
LIB_DEPENDS=	libconfig.so:devel/libconfig

BROKEN_aarch64=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv6=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USES=		cmake
CMAKE_ARGS+=	-DD_COMPILER:STRING="${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/}/bin/ldmd2" \
		-DBUILD_SHARED_LIBS:STRING="BOTH"

CC=		clang40
CXX=		clang++40

BOOTVER=	0.17.5
LLVM_CONFIG=	llvm-config40
LDCVER=		${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/-src/}

DISTFILES+=	${PORTNAME}-${BOOTVER}-src.tar.gz:bootstrap

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$${llvm_config_names}|${LLVM_CONFIG}|g' \
		${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/}/cmake/Modules/FindLLVM.cmake \
		${WRKSRC}/cmake/Modules/FindLLVM.cmake

pre-configure:
	@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && \
	    ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} .
	@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && \
	    ${SETENV} ${MAKE_ENV} ${MAKE}

.include <bsd.port.post.mk>
