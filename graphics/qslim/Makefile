# ex:ts=8
# Ports collection makefile for:	qslim
# Date created:			Jan 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qslim
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlimKit Surface Modeling Tools

BUILD_DEPENDS=	${LOCALBASE}/include/gfx/gfx.h:${PORTSDIR}/graphics/libgfx
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		forms.1:${PORTSDIR}/x11-toolkits/xforms

CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}/mixkit
BUILD_WRKSRC=		${WRKDIR}/${DISTNAME}/mixkit/src

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_GL=		glu
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	# none

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fpermissive

pre-configure:
	@(cd ${CONFIGURE_WRKSRC}/../libgfx && ${SETENV} ${CONFIGURE_ENV} \
	    CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
	    CXXFLAGS="${CXXFLAGS}" ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-build:
	@(cd ${BUILD_WRKSRC}/../../tools/qslim && ${SETENV} ${MAKE_ENV} \
	${GMAKE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${INSTALL_DATA} ${WRKSRC}/mixkit/src/libmix.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qslim ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qvis ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/mixkit
	${INSTALL_DATA} ${WRKSRC}/mixkit/src/*.h ${PREFIX}/include/mixkit

.include <bsd.port.mk>
