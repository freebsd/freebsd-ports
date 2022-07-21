PORTNAME=	madronalib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6-1016
DISTVERSIONSUFFIX=	-g103895f
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ framework for DSP applications

LICENSE=	MIT

BROKEN_aarch64=	fails to build: error: unknown type name '__m128'
BROKEN_armv6=	fails to build: error: unknown type name '__m128'
BROKEN_armv7=	fails to build: error: unknown type name '__m128'
BROKEN_i386=	error: always_inline function '_mm_load_ps' requires target feature 'sse', but would be inlined into function 'add' that is compiled without support for 'sse'
BROKEN_riscv64=	error: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake localbase:ldflags perl5

USE_GITHUB=	yes
GH_ACCOUNT=	madronalabs

CMAKE_ON=	LINUX_JACK

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CXXFLAGS+=	-DNO_WARN_X86_INTRINSICS -maltivec -mvsx
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lib
.endif

.include <bsd.port.mk>
