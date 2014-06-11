# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3plot
DISTVERSION=	0.6.0
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://p.outlyer.net/mp3plot/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mp3 bitrate plot tool

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	GD IMAGEMAGICK
OPTIONS_DEFAULT=	GD

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-boost-program-options=boost_program_options \
		--with-boost-thread=boost_thread

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lboost_system

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd
.else
CONFIGURE_ARGS+=	--disable-gd
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	libMagick++.so:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--disable-magick
.endif

post-patch:
	@${REINPLACE_CMD} -e '/bldtype_/s|-O2||g' \
		-e 's|^extra_LD.*||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
