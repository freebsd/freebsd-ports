# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3plot
DISTVERSION=	0.6.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://p.outlyer.net/mp3plot/files/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Mp3 bitrate plot tool

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	GD IMAGEMAGICK
OPTIONS_DEFAULT=	GD

LICENSE=	GPLv2

NO_STAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-boost-program-options=boost_program_options \
		--with-boost-thread=boost_thread
CONFIGURE_ENV+=	"LIBS=-lboost_system"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

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
