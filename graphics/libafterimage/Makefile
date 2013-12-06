# Created by: ijliao
# $FreeBSD$

PORTNAME=	libafterimage
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/afterstep/libAfterImage/${PORTVERSION}
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic imaging library originally designed for AfterStep

BROKEN=		Fails to build

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		gif.5:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

LICENSE=	LGPL21

USE_BZIP2=	yes
USE_XORG=	xext
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs \
		--without-builtin-ungif --without-afterbase \
		--with-x
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		ascompose.1x

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx-optimization
.else
CONFIGURE_ARGS+=	--disable-mmx-optimization
.endif

post-extract:
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libAfterImage

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-O3"||g ; \
		 s| malloc\.h | |g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/apps/ascompose.man \
		${MANPREFIX}/man/man1/ascompose.1x

.include <bsd.port.post.mk>
