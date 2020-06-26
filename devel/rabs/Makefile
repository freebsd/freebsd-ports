# $FreeBSD$

PORTNAME=	rabs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
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
GH_TUPLE=	wrapl:minilang:211c6449c1f2a07ab7f2aea7224c416cd9c957a3:wrapl_minilang/minilang \
		rajamukherji:radb:4d9c68a8e51dc1bc6999a95a8fdad66a18a25b38:rajamukherji_radb/radb

MAKE_ARGS=	PREFIX=${PREFIX}
BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/rabs

.include <bsd.port.mk>
