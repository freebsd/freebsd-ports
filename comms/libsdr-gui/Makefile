# Created by: Jeffrey Baitis <jeff@baitis.net>
# $FreeBSD$

PORTNAME=	libsdr-gui
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio

MAINTAINER=	jeff@baitis.net
COMMENT=	GUI functions (e.g. waterfall) for libsdr library

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsdr.so:comms/libsdr

USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek

USE_QT5=	core buildtools_build qmake widgets
USES=		cmake pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
