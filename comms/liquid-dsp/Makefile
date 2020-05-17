# $FreeBSD$

PORTNAME=	liquid-dsp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Software-Defined Radio Digital Signal Processing Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		autoreconf gmake iconv:wchar_t libtool localbase

USE_GITHUB=	yes
GH_ACCOUNT=	jgaeddert
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libliquid.so

.include <bsd.port.mk>
