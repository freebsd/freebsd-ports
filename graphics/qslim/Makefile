# ex:ts=8
# Ports collection makefile for:	qslim
# Date created:			Jan 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qslim
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlimKit Surface Modeling Tools

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		forms.1:${PORTSDIR}/x11-toolkits/xforms \
		glut.4:${PORTSDIR}/graphics/libglut

CONFIGURE_WRKSRC=	${WRKSRC}/mixkit/build
BUILD_WRKSRC=	${WRKSRC}/mixkit/src

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	# none

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${X11BASE}/include/X11 ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fpermissive

post-extract:
	@${RM} -f ${WRKSRC}/mixkit/src/getopt.h

post-patch:
	@${REINPLACE_CMD} -e 's|\@XFORMS_LIBS\@|-lforms -lformsGL -lXpm|g' \
		${CONFIGURE_WRKSRC}/mix-config.in

post-build:
	@(cd ${BUILD_WRKSRC}/../../tools/qslim ; ${GMAKE} all)
	@(cd ${BUILD_WRKSRC}/../../tools/filters ; ${GMAKE} all)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mixkit/src/libmix.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qslim ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qvis ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/mixkit
	${INSTALL_DATA} ${WRKSRC}/mixkit/src/*.h ${PREFIX}/include/mixkit

.include <bsd.port.mk>
