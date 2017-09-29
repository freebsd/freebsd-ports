# Created by: Iouri V. Ivliev
# $FreeBSD$

PORTNAME=	pfstmo
PORTVERSION=	1.5
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/pfstools/${PORTNAME}_depreciated/${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Tone mapping operators

USE_GCC=	any

LIB_DEPENDS=	libpfs-1.2.so:graphics/pfstools \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${PFS_CPPFLAGS} ${DEBUG_FLAGS}" \
		LDFLAGS="${PFS_LDFLAGS}"

USES=		gmake pkgconfig compiler:openmp
# GCC 6 defaults to -std=gnu++14, and the port does not build with C++11 or
# later (bug 219299).
USE_CXXSTD=	gnu++03

.include <bsd.port.mk>
