# ex:ts=8
# Ports collection Makefile for:	ale
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ale
PORTVERSION=	0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://auricle.dyndns.org/ALE/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Lamenessing Engine

PLIST_FILES=	bin/ale
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif

.if !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.6:${PORTSDIR}/graphics/ImageMagick
MAKE_ARGS+=	IMAGEMAGICK=1
.endif

.if !defined(WITHOUT_FFTW3)
LIB_DEPENDS+=	fftw3.3:${PORTSDIR}/math/fftw3
MAKE_ARGS+=	FFTW=1
.endif

pre-everything::
.if !defined(WITHOUT_IMAGEMAGICK)
	@${ECHO_MSG} "===> Disable ImageMagick Support by defining WITHOUT_IMAGEMAGICK"
.endif
.if !defined(WITHOUT_FFTW3)
	@${ECHO_MSG} "===> Disable FFTW3 Support by defining WITHOUT_FFTW3"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|; \
		s|g++|${CXX}|'	${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/*.h ${WRKSRC}/*/*.h
.if ${OSVERSION} < 502114
	@${REINPLACE_CMD} -e 's|round|rint|' \
		${WRKSRC}/d2/image_rw.h \
		${WRKSRC}/d2/ppm.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ale ${PREFIX}/bin

.include <bsd.port.post.mk>
