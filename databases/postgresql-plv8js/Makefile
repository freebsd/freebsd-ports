# Created by: vanilla@

PORTNAME=	plv8
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
PKGNAMESUFFIX=	js

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LICENSE=	PostgreSQL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libv8.so:lang/v8

USES=		compiler:c++14-lang gmake perl5 pgsql:9.6-10
USE_PERL5=	build
USE_GITHUB=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

CXXFLAGS+=	-std=c++14
MAKEFILE=	Makefile.shared
MAKE_ARGS=	CUSTOM_CC=${CXX} CCFLAGS="${CXXFLAGS}"

.include <bsd.port.mk>
