# Created by: ijliao
# $FreeBSD$

PORTNAME=	qslim
PORTVERSION=	2.1
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://mgarland.org/files/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlimKit surface modeling tools

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libgfx.so:graphics/libgfx

CONFIGURE_WRKSRC=	${WRKSRC}/mixkit
BUILD_WRKSRC=		${WRKSRC}/mixkit/src

USES=		gmake
USE_GL=		glu
GNU_CONFIGURE=	yes
MAKE_ENV=	FLTKCONFIG="${FLTK_CONFIG}" GUI_LIBS="${GUI_LIBS}"
MAKE_ARGS=	CC="${CC}" CXX="${CXX}"
ALL_TARGET=	# none
USE_LDCONFIG=	yes

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -DHAVE_BOOL -fPIC -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

FLTK_CONFIG=	${LOCALBASE}/bin/fltk-config
GUI_LIBS=	$$(${FLTK_CONFIG} --use-gl --ldflags)

post-extract:
	@${RM} -rf ${WRKSRC}/libgfx/

post-patch:
	@${REINPLACE_CMD} -e '/gfx-config/d' ${CONFIGURE_WRKSRC}/mix-config.in
	@${REINPLACE_CMD} -e 's/\.\..*mix\.a//' ${WRKSRC}/tools/qslim/Makefile
	@${REINPLACE_CMD} -e '/gfx-config/d;s/\.a/.so/g;s/[(]AR[)] cru/(CXX) \
		$$(CXXFLAGS) -shared -o/;/RANLIB/d' ${BUILD_WRKSRC}/${MAKEFILE}
.for i in mixkit/src/Makefile tools/qslim/Makefile
	@${ECHO_CMD} '.SUFFIXES: .fl .c .cc .cxx .o' >> ${WRKSRC}/${i}
	@${ECHO_CMD} '.cxx.o:' >> ${WRKSRC}/${i}
	@${ECHO_CMD} '	$$(CXX) -c $$(CXXFLAGS) $$<' >> ${WRKSRC}/${i}
.endfor

post-build:
	@(cd ${BUILD_WRKSRC}/../../tools/qslim && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
.for i in qslim qvis
	(cd ${WRKSRC}/tools/qslim && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/mixkit
	(cd ${WRKSRC}/mixkit/src && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/mixkit)
	(cd ${WRKSRC}/mixkit/src && ${INSTALL_PROGRAM} libmix.so \
		${STAGEDIR}${PREFIX}/lib)
	@${LN} -sf libmix.so ${STAGEDIR}${PREFIX}/lib/libmix.so.0

.include <bsd.port.mk>
