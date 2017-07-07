# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldc
PORTVERSION=	1.2.0
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
BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USES=		cmake
CMAKE_ARGS+=	-DD_COMPILER:STRING="${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/}/bin/ldmd2"
CC=		clang39

BOOTVER=	0.17.3
LDCVER=		${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/-src/}

DISTFILES+=	${PORTNAME}-${BOOTVER}-src.tar.gz:bootstrap

pre-configure:
		@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && ${CMAKE_BIN} .
		@cd ${WRKDIR}/${PORTNAME}-${BOOTVER:S/$/-src/} && ${MAKE}

.include <bsd.port.mk>
