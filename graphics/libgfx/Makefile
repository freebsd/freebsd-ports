# New ports collection makefile for:	libgfx
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgfx
DISTVERSION=	1.1.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://mgarland.org/files/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL/FLTK development

LICENSE=	MIT

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk \
		tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		gzstream:${PORTSDIR}/devel/gzstream \
		jpeg:${PORTSDIR}/graphics/jpeg

BUILD_WRKSRC=	${WRKSRC}/src

USE_GL=		glu
USE_GMAKE=	yes
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
	@(cd ${WRKSRC}/include/gfx && ${COPYTREE_SHARE} . ${PREFIX}/include/gfx)
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}.so ${PREFIX}/lib
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.mk>
