# ex:ts=8
# Ports collection makefile for:	qslim
# Date created:			Jan 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qslim
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlimKit Surface Modeling Tools

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gfx.0:${PORTSDIR}/graphics/libgfx \
		forms.1:${PORTSDIR}/x11-toolkits/xforms

CONFIGURE_WRKSRC=	${WRKSRC}/mixkit
BUILD_WRKSRC=		${WRKSRC}/mixkit/src

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_GL=		glu
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	# none

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -DHAVE_BOOL
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fpermissive -fPIC ${CPPFLAGS}
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"
MAKE_ENV+=	LDFLAGS="${LDFLAGS}" FLTKCONFIG="${LOCALBASE}/bin/fltk-config"

post-extract:
	@${RM} -rf ${WRKSRC}/libgfx/

post-patch:
	@${REINPLACE_CMD} -e '/gfx-config/d' ${CONFIGURE_WRKSRC}/mix-config.in
	@${REINPLACE_CMD} -e 's/\.\..*mix\.a//' ${WRKSRC}/tools/qslim/Makefile
	@${REINPLACE_CMD} -e '/gfx-config/d;s/\.a/.so/g;s/[(]AR[)] cru/(CXX) \
		$$(CXXFLAGS) -shared -o/;/RANLIB/d' ${BUILD_WRKSRC}/${MAKEFILE}
	@for f in ${BUILD_WRKSRC}/Makefile ${WRKSRC}/tools/qslim/Makefile;do\
		${ECHO_CMD} '.SUFFIXES: .fl .c .cc .cxx .o' >> $$f;\
		${ECHO_CMD} '.cxx.o:' >> $$f;\
		${ECHO_CMD} '	$$(CXX) -c $$(CXXFLAGS) $$<' >> $$f;done

post-build:
	@(cd ${BUILD_WRKSRC}/../../tools/qslim && ${SETENV} ${MAKE_ENV} \
	${GMAKE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mixkit/src/libmix.so ${PREFIX}/lib/
	@${LN} -sf libmix.so ${PREFIX}/lib/libmix.so.0
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qslim ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/qslim/qvis ${PREFIX}/bin/
	@${INSTALL} -d ${PREFIX}/include/mixkit/
	@${INSTALL_DATA} ${WRKSRC}/mixkit/src/*.h ${PREFIX}/include/mixkit/

.include <bsd.port.mk>
