# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

OPTIONS=	DOUBLE "64bit Data Precision Support" off \
		FFTW3 "FFTW3 Support" on \
		IMAGEMAGICK "ImageMagick Support" on

USE_GCC=	3.4+
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" IOCTL=1

PLIST_FILES=	bin/ale

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

.if ${OSVERSION} < 502114
CFLAGS+=	-Dround=rint
.endif

.if defined(WITH_DOUBLE)
MAKE_ARGS+=	COLORS=DOUBLE COORDINATES=DOUBLE
.endif

.if !defined(WITHOUT_FFTW3)
LIB_DEPENDS+=	fftw3.4:${PORTSDIR}/math/fftw3
MAKE_ARGS+=	FFTW=1
.endif

.if !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.9:${PORTSDIR}/graphics/ImageMagick
MAKE_ARGS+=	IMAGEMAGICK=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/d2.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ale ${PREFIX}/bin

.include <bsd.port.post.mk>
