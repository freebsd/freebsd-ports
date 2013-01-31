# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3plot
DISTVERSION=	0.6.0
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://p.outlyer.net/mp3plot/files/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Mp3 bitrate plot tool

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

OPTIONS=	GD "Enable support for GD library" on \
		IMAGEMAGICK "Enable support for Magick++" off

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-boost-program-options=boost_program_options \
		--with-boost-thread=boost_thread
CONFIGURE_ENV+=	"LIBS=-lboost_system"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GD)
CONFIGURE_ARGS+=	--disable-gd
.else
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick++.5:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--disable-magick
.endif

post-patch:
	@${REINPLACE_CMD} -e '/bldtype_/s|-O2||g' \
		-e 's|^extra_LD.*||g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
