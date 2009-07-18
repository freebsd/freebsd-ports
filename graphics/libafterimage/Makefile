# ex:ts=8
# New ports collection makefile for:	libAfterImage
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterimage
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/afterstep
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic imaging library originally designed for AfterStep

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_XORG=	xext
USE_GNOME=	gnometarget librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs \
		--without-builtin-ungif --without-afterbase \
		--with-x
USE_LDCONFIG=	yes

MAN1=	ascompose.1x
MAN3=	ascmap.3x afterimage.3x ascompose.3x asflip.3x asfont.3x asgrad.3x	\
	asimage.3x asimagexml.3x asmerge.3x asscale.3x astext.3x astile.3x	\
	asview.3x asvisual.3x blender.3x char2uni.3x common.3x export.3x	\
	imencdec.3x import.3x transform.3x ximage.3x

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
		 s| malloc\.h | |g ; \
		 s|-lgif|-lungif|g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/apps/ascompose.man \
		${MANPREFIX}/man/man1/ascompose.1x

.include <bsd.port.post.mk>
