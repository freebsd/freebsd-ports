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
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://kogs-www.informatik.uni-hamburg.de/~koethe/vigra/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	cartola@openit.com.br
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fftw3:${PORTSDIR}/math/fftw3

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tiff \
		--with-jpeg \
		--with-png \
		--with-zlib \
		--with-fftw \
		--docdir=${PREFIX}/share/doc/vigra
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
