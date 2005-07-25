# New ports collection makefile for:	yafray
# Date created:				18 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	yafray
PORTVERSION=	0.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.coala.uniovi.es/~jandro/noname/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A fast XML based raytracer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500000
USE_GCC=3.4+
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -E -e \
		's|^CXX =.+$$|CXX=${CXX}|; \
		s|-O3||; \
		s|-D_PTHREADS||; \
		s|-pthread|-lpthread|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|-ffast-math||; \
		s|-ldl||; \
		s|-Wall|${CXXFLAGS}|'

	@${FIND} ${WRKSRC} -name "configure.in" \
		-or -name "configure" | ${XARGS} \
		${REINPLACE_CMD} -E -e \
		's|-pthread|-lpthread|g; \
		s|-lpthread|${PTHREAD_LIBS}|g'

#make sure we don't need to run auto****
	@${TOUCH} ${TOUCH_FLAGS} -t 199705212205.21 \
		${WRKSRC}/configure.in

.include <bsd.port.post.mk>
