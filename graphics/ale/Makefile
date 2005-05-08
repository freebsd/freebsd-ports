# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.8.1
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

USE_GCC=	3.4
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" IOCTL=1

PLIST_FILES=	bin/ale

OPTIONS=	DOUBLE "64bit Data Precision Support" off \
		FFTW3 "FFTW3 Support" on \
		IMAGEMAGICK "ImageMagick Support" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not build on alpha"
.endif

.if defined(WITH_DOUBLE)
MAKE_ARGS+=	COLORS=DOUBLE COORDINATES=DOUBLE
.endif

.if !defined(WITHOUT_FFTW3)
LIB_DEPENDS+=	fftw3.3:${PORTSDIR}/math/fftw3
MAKE_ARGS+=	FFTW=1
.endif

.if !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.8:${PORTSDIR}/graphics/ImageMagick
MAKE_ARGS+=	IMAGEMAGICK=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/d2.h
.if ${OSVERSION} < 502114
.for file in d2/image_rw.h d2/ppm.h d3/scene.cc
	@${REINPLACE_CMD} -e 's|round|rint|g' ${WRKSRC}/${file}
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ale ${PREFIX}/bin

.include <bsd.port.post.mk>
