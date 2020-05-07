# $FreeBSD$

PORTNAME=	rabs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.4
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
GH_TUPLE=	wrapl:minilang:3546326eee957d55b6d2be0b872c3f7df3b39b1b:wrapl_minilang/minilang \
		rajamukherji:radb:5ecc0833f0e7358ff122461f534d249178f973d7:rajamukherji_radb/radb

MAKE_ARGS=	PREFIX=${PREFIX}
BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/rabs

.include <bsd.port.mk>
