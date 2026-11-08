PORTNAME=	codec2
DISTVERSION=	1.2.0
CATEGORIES=	audio hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Low bit rate codec
WWW=		https://www.rowetel.com/?page_id=452

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pkgconfig python tar:xz

GH_ACCOUNT=	drowe67
GH_PROJECT=	codec2

USE_LDCONFIG=	yes
USE_GITHUB=	yes

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SUB=	yes
EXAMPLES_CMAKE_ON=	-DINSTALL_EXAMPLES=ON
TEST_CMAKE_ON=		-DUNITTEST=ON

#TEST_RUN_DEPENDS=	octave:math/octave
#TEST_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

PORTEXAMPLES=	*

.include <bsd.port.mk>
