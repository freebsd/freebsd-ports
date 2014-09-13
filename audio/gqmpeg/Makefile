# Created by: Vanilla Pooh Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gqmpeg
PORTVERSION=	0.20.0
PORTREVISION=	11
PORTEPOCH=	2
CATEGORIES+=	audio
MASTER_SITES=	SF

MAINTAINER?=	lyngbol@wheel.dk
COMMENT?=	Another gtk-based MP3 frontend

OPTIONS_DEFINE=	MPG321
MPG321_DESC=	use mpg321 instead of mpg123

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools \
		xmp:${PORTSDIR}/audio/xmp

MPG321_RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321
MPG321_RUN_DEPENDS_OFF=	mpg123:${PORTSDIR}/audio/mpg123

USE_GNOME=	gdkpixbuf
USES=		gettext libtool
USE_AUTOTOOLS=	autoconf213
CONFIGURE_ENV+=	USE_GNOME=""

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E -e \
		's/^(#define MPG123_BINARY "mpg)123"/\1321"/' \
		${WRKSRC}/src/io_mpg123.c

.include <bsd.port.mk>
