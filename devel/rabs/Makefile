# $FreeBSD$

PORTNAME=	rabs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic imperative build system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembly: Error: unrecognized opcode: 'int3'

LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded

USES=		compiler:c11 gmake localbase:ldflags sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	wrapl
GH_TUPLE=	\
		wrapl:minilang:014189470375c1bee6e402dc9539cc30db5cd55b:wrapl_minilang/minilang \
		rajamukherji:radb:b2b9d9fca77fb130ffe3e5d6f11b3e8a2e99ebb8:rajamukherji_radb/radb

MAKE_ARGS=	PREFIX=${PREFIX}
BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/rabs

.include <bsd.port.mk>
