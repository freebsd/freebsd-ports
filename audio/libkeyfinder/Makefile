PORTNAME=	libkeyfinder
PORTVERSION=	2.2.8
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Small C++11 library for estimating the musical key of digital audio
WWW=		https://github.com/mixxxdj/libkeyfinder

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	mixxxdj

CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=OFF

.include <bsd.port.mk>
