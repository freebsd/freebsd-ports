PORTNAME=	madronalib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6-1016
DISTVERSIONSUFFIX=	-g103895f
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ framework for DSP applications

LICENSE=	MIT

BROKEN_i386=	error: always_inline function '_mm_load_ps' requires target feature 'sse', but would be inlined into function 'add' that is compiled without support for 'sse'

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake compiler:c++11-lib localbase:ldflags perl5

USE_GITHUB=	yes
GH_ACCOUNT=	madronalabs

CMAKE_ON=	LINUX_JACK

.include <bsd.port.mk>
