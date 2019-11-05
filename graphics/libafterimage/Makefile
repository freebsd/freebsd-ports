# Created by: ijliao
# $FreeBSD$

PORTNAME=	libafterimage
PORTVERSION=	1.20
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/afterstep/libAfterImage/${PORTVERSION}
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic imaging library originally designed for AfterStep

LICENSE=	LGPL21+

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2

USES=		gnome jpeg pkgconfig tar:bzip2 xorg
USE_XORG=	xext
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs \
		--without-builtin-ungif --without-afterbase \
		--with-x
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE_amd64=	MMX
OPTIONS_DEFINE_i386=	MMX

MMX_CONFIGURE_ENABLE=	mmx-optimization

post-extract:
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libAfterImage

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-O3"||g ; \
		 s| malloc\.h | |g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libAfterImage.so
	(cd ${WRKSRC}/apps && ${INSTALL_MAN} ascompose.man \
		${STAGEDIR}${MANPREFIX}/man/man1/ascompose.1x)

.include <bsd.port.mk>
