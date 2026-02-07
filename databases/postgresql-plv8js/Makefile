PORTNAME=	plv8
PORTVERSION=	3.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
PKGNAMESUFFIX=	js

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database
WWW=		https://plv8.github.io/

LICENSE=	PostgreSQL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libv8.so:lang/v8

USES=		compiler:c++17-lang gmake pgsql
USE_GITHUB=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

CXXFLAGS+=	-std=c++17 -fno-rtti
# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && ${ARCH} != powerpc && ${ARCH} != powerpcspe
CXXFLAGS+=	-DV8_COMPRESS_POINTERS=1 -DV8_31BIT_SMIS_ON_64BIT_ARCH=1
.endif
MAKE_ARGS=	CUSTOM_CC=${CXX} CCFLAGS="${CXXFLAGS}"

.include <bsd.port.mk>
