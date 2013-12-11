# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	xplanet
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Draw pictures of the earth textured by an image

NO_STAGE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	xt xscrnsaver
USE_GNOME=	#
CONFIGURE_ARGS=	--with-map-extension=jpg
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lm"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	FREETYPE PANGO GIF JPEG PNG PNM TIFF
OPTIONS_DEFAULT= FREETYPE PANGO GIF JPEG PNG PNM TIFF

MAN1=	xplanet.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFREETYPE}
CONFIGURE_ARGS+=	--with-freetype
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if ${PORT_OPTIONS:MPANGO}
CONFIGURE_ARGS+=	--with-pango
USE_GNOME+=	pango
.else
CONFIGURE_ARGS+=	--without-pango
.endif

.if ${PORT_OPTIONS:MGIF}
CONFIGURE_ARGS+=	--with-gif
LIB_DEPENDS+=	libgif.so:${PORTSDIR}/graphics/giflib
.else
CONFIGURE_ARGS+=	--without-gif
.endif

.if ${PORT_OPTIONS:MJPEG}
CONFIGURE_ARGS+=	--with-jpeg
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if ${PORT_OPTIONS:MPNG}
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if ${PORT_OPTIONS:MPNM}
CONFIGURE_ARGS+=	--with-pnm
LIB_DEPENDS+=	libnetpbm.so:${PORTSDIR}/graphics/netpbm
.else
CONFIGURE_ARGS+=	--without-pnm
.endif

.if ${PORT_OPTIONS:MTIFF}
CONFIGURE_ARGS+=	--with-tiff
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

post-extract:
	@${REINPLACE_CMD} -e "s/default/default.sample/g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s/PrintGifError();/GifError();/g" \
		${WRKSRC}/src/libimage/gif.c
	@${MV} ${WRKSRC}/xplanet/config/default ${WRKSRC}/xplanet/config/default.sample

post-install:
.for file in freebsd.committers.markers freebsd.ftp.markers
.if exists(${PORTSDIR}/astro/xearth/files/${file})
	@${INSTALL_DATA} ${PORTSDIR}/astro/xearth/files/${file} \
		${DATADIR}/markers
.endif
.endfor
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@if test ! -f ${DATADIR}/config/default; then \
		${CP} ${DATADIR}/config/default.sample ${DATADIR}/config/default; \
	fi

.include <bsd.port.post.mk>
