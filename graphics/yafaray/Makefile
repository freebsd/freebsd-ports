# New ports collection makefile for:	yafray
# Date created:				18 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	yafray
PORTVERSION=	0.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.coala.uniovi.es/~jandro/noname/downloads/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A fast XML based raytracer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -E -e \
		's|^CXX =.+$$|CXX=${CXX}|; \
		s|-O3||; \
		s|-ffast-math||; \
		s|-Wall|${CXXFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
