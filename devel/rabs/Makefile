# $FreeBSD$

PORTNAME=	rabs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
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
GH_TUPLE=	wrapl:minilang:9f61ac1:m/minilang \
		rajamukherji:radb:5ecc083:d/radb

MAKE_ARGS=	PREFIX=${PREFIX}
BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/rabs

.include <bsd.port.mk>
