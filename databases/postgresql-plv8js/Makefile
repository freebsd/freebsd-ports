PORTNAME=	plv8
PORTVERSION=	3.0.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
PKGNAMESUFFIX=	js

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LICENSE=	PostgreSQL

BROKEN=		does not build: plv8.cc:1397:20: error: no matching constructor for initialization of 'v8::ScriptOrigin'

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libv8.so:lang/v8

USES=		compiler:c++14-lang gmake perl5 pgsql
USE_PERL5=	build
USE_GITHUB=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

CXXFLAGS+=	-std=c++14 -fno-rtti \
		-DV8_COMPRESS_POINTERS=1 -DV8_31BIT_SMIS_ON_64BIT_ARCH=1
MAKEFILE=	Makefile.shared
MAKE_ARGS=	CUSTOM_CC=${CXX} CCFLAGS="${CXXFLAGS}"

.include <bsd.port.mk>
