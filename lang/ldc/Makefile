# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldc
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ldc-developers/ldc/releases/download/v${PORTVERSION}/:source \
		https://github.com/ldc-developers/ldc/releases/download/v${BOOTVER}/:bootstrap
DISTFILES=	${DISTNAME:S/$/-src/}${EXTRACT_SUFX}:source

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The LLVM-based D compiler

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	clang39:devel/llvm39
LIB_DEPENDS=	libconfig.so:devel/libconfig

BROKEN_aarch64=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv6=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USES=		cmake
CMAKE_ARGS+=	-DD_COMPILER:STRING="${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/}/bin/ldmd2" \
		-DBUILD_SHARED_LIBS:STRING="BOTH"

CC=		clang39
CXX=		clang++39

BOOTVER=	0.17.5
LDCVER=		${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/-src/}

DISTFILES+=	${PORTNAME}-${BOOTVER}-src.tar.gz:bootstrap

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
PLIST_SUB+=	LDC_I386=""
.elif ${ARCH} == "i386"
PLIST_SUB+=	LDC_I386="@comment "
.endif

pre-configure:
		@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && ${CMAKE_BIN} .
		@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && ${MAKE}

.include <bsd.port.post.mk>
