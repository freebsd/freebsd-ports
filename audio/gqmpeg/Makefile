# Created by: Vanilla Pooh Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gqmpeg
PORTVERSION=	0.20.0
PORTREVISION=	12
PORTEPOCH=	2
CATEGORIES+=	audio
MASTER_SITES=	SF

MAINTAINER?=	lyngbol@wheel.dk
COMMENT?=	Another gtk-based MP3 frontend

OPTIONS_DEFINE=	MPG321
MPG321_DESC=	use mpg321 instead of mpg123

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	ogg123:audio/vorbis-tools \
		xmp:audio/xmp

MPG321_RUN_DEPENDS=	mpg321:audio/mpg321
MPG321_RUN_DEPENDS_OFF=	mpg123:audio/mpg123

USE_GNOME=	gdkpixbuf
USES=		gettext libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GNOME_CONFIG=no

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -E -e \
		's/^(#define MPG123_BINARY "mpg)123"/\1321"/' \
		${WRKSRC}/src/io_mpg123.c

.include <bsd.port.mk>
