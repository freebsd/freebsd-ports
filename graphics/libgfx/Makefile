# New ports collection makefile for:	libgfx
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgfx
DISTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL/FLTK development

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		gzstream.0:${PORTSDIR}/devel/gzstream \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_GL=		gl
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-gzstream --with-libtiff-lzw --with-x
CFLAGS=		-I${LOCALBASE}/include -fPIC
LDFLAGS=	-L${LOCALBASE}/lib
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	${PORTNAME}.so
MAKE_ARGS=	CC="${CC}" CXX="${CXX}"

post-patch:
	@${REINPLACE_CMD} -e '/^CC /d;/^CXX /d' ${WRKSRC}/gfx-config.in
	@${REINPLACE_CMD} -e 's|\.a|.so|g;/RANLIB/d;s|[(]AR[)] cru|{CC} \
		${CFLAGS} ${LDFLAGS} -shared $${GUI_LIBS} -lgzstream -o|'\
		${WRKSRC}/src/${MAKEFILE}

do-install:
	@cd ${WRKSRC}/include/gfx/&&${COPYTREE_SHARE} . ${PREFIX}/include/gfx/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}.so ${PREFIX}/lib/
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.mk>
