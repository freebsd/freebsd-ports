# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgfx
DISTVERSION=	1.1.0
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://mgarland.org/files/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL/FLTK development

LICENSE=	MIT

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libgzstream.so:devel/gzstream

BUILD_WRKSRC=	${WRKSRC}/src

USES=		gmake jpeg
USE_GL=		glu
USE_XORG=	x11 xext xft xinerama
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gzstream --with-libtiff-lzw --with-x
ALL_TARGET=	${PORTNAME}.so
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC /d ; \
		 /^CXX /d' ${WRKSRC}/gfx-config.in
	@${REINPLACE_CMD} -e \
		's|\.a|.so|g ; \
		 /RANLIB/d ; \
		 s|[(]AR[)] cru|{CC} ${CFLAGS} ${LDFLAGS} -shared $${GUI_LIBS} -lgzstream -o|' ${WRKSRC}/src/${MAKEFILE}
	@${REINPLACE_CMD} -e \
		'/^FLTK_LIBS/s|"-lfltk"|"`fltk-config --ldflags`"|' ${WRKSRC}/configure

do-install:
	@(cd ${WRKSRC}/include/gfx && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/gfx)
	${INSTALL_LIB} ${WRKSRC}/src/${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib
	@${LN} -sf ${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.mk>
