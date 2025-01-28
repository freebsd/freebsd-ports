PORTNAME=	rabs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic imperative build system
WWW=		https://github.com/wrapl/rabs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembly: Error: unrecognized opcode: 'int3'

LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded

USES=		compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	wrapl
GH_TUPLE=	wrapl:minilang:b4db639:wrapl_minilang/minilang \
		rajamukherji:radb:b6f1ba8:rajamukherji_radb/radb \
		\
		wrapl:tre:4482069fe70912412d89487aa214b103779ad037:wrapl_tre/minilang/src/tre \
		derickr:timelib:4d83163b58650559ab8964cb2c8de57964fd86c9:derickr_timelib/minilang/src/timelib \
		rajamukherji:minicbor:05c4171a30fcd8ec0efc6aa1b02dde4905e1283a:rajamukherji_minicbor/minilang/src/minicbor \
		ianlancetaylor:libbacktrace:d48f84034ce3e53e501d10593710d025cb1121db:ianlancetaylor_libbacktrace/minilang/src/libbacktrace \
		ivmai:bdwgc:ee59af3722e56de8404de6cd0c21c2493cc4d855:ivmai_bdwgc/minilang/src/gc

MAKE_ARGS=	PREFIX=${PREFIX}
BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/rabs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rabs

.include <bsd.port.mk>
