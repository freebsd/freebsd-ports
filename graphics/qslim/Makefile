# ex:ts=8
# Ports collection makefile for:	qslim
# Date created:			Jan 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qslim
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xforms:${PORTSDIR}/x11-toolkits/xforms \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png

USE_MESA=	yes
USE_XLIB=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/mixkit/build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt -L${X11BASE}/lib ${PTHREAD_LIBS}"
BUILD_WRKSRC=	${WRKSRC}/mixkit/src
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-build:
	@(cd ${BUILD_WRKSRC}/../../tools/qslim ; ${GMAKE} all)
	@(cd ${BUILD_WRKSRC}/../../tools/filters ; ${GMAKE} all)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mixkit/src/libmix.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qslim ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qvis ${PREFIX}/bin

.include <bsd.port.mk>
