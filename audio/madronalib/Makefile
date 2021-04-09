PORTNAME=	madronalib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6-1016
DISTVERSIONSUFFIX=	-g103895f
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ framework for DSP applications

LICENSE=	MIT

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cmake compiler:c++11-lib localbase:ldflags perl5

USE_GITHUB=	yes
GH_ACCOUNT=	madronalabs

CMAKE_ON=	LINUX_JACK

.include <bsd.port.mk>
