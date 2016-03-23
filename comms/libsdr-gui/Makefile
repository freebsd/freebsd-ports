# Created by: Jeffrey Baitis <baitisj@pcbsd.org>
# $FreeBSD$

PORTNAME=	libsdr-gui
PORTVERSION=	0.1.0
CATEGORIES=	comms hamradio

MAINTAINER=	baitisj@pcbsd.org
COMMENT=	GUI functions (e.g. waterfall) for libsdr library

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsdr.so:${PORTSDIR}/comms/libsdr

USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek
GH_PROJECT=	libsdr-gui
GH_TAGNAME=	96846d1

USE_QT5=	core buildtools_build qmake widgets
USES=		cmake pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
