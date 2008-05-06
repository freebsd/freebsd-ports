# New ports collection makefile for:    raw images library
# Date created:         26 Apr 2008
# Whom:                 osa
#
# $FreeBSD$
#

PORTNAME=	libraw
PORTVERSION=	0.5.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.su/data/
DISTNAME=	LibRaw-${PORTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for manipulating raw images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

MAKE_ENV+=	CXX="${CXX}" CC="${CC}" CFLAGS="${CFLAGS}" \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

USE_LDCONFIG=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/libraw

.for f in libraw.h libraw_alloc.h libraw_const.h libraw_internal.h libraw_io.h libraw_types.h
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${PREFIX}/include/libraw
.endfor
.for f in libraw.a libraw.so.0 libraw_r.a libraw_r.so.0
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
.endfor
.for f in libraw libraw_r
	@ cd ${PREFIX}/lib ; ${LN} -sf ${f}.so.0 ${f}.so
.endfor

.include <bsd.port.mk>
