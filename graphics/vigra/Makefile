# New ports collection makefile for:   panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#
# This port has been made as a building dependence for the hugin port.
# As far as I could test the hugin port runs without this port installed, so the package
# does not need to refer to this dependence.
# The hugin port is a gui interface to interact with panorama tools.

PORTNAME=	vigra
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://kogs-www.informatik.uni-hamburg.de/~koethe/vigra/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	cartola@openit.com.br
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"

USE_AUTOTOOLS=	libtool:15
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${PREFIX}/share/doc/vigra
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_VIGRA_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if !defined(WITHOUT_VIGRA_JPEG)
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if !defined(WITHOUT_VIGRA_PNG)
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !defined(WITHOUT_VIGRA_ZLIB)
CONFIGURE_ARGS+=	--with-zlib
.else
CONFIGURE_ARGS+=	--without-zlib
.endif

.if !defined(WITHOUT_VIGRA_FFTW)
LIB_DEPENDS+=		fftw3:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS+=	--with-fftw
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

.include <bsd.port.mk>
