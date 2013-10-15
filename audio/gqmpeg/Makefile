# Created by: Vanilla Pooh Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gqmpeg
PORTVERSION=	0.20.0
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES+=	audio
MASTER_SITES=	SF

MAINTAINER?=	lyngbol@wheel.dk
COMMENT?=	Another gtk-based MP3 frontend

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools \
		xmp:${PORTSDIR}/audio/xmp

.if defined(WITH_MPG321)
RUN_DEPENDS+=	mpg321:${PORTSDIR}/audio/mpg321
.else
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif

USE_GNOME=	gdkpixbuf
NO_STAGE=	yes
USES=		gettext
USE_AUTOTOOLS=	autoconf213 libtool
CONFIGURE_ENV+=	USE_GNOME=""

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

MAN1=		gqmpeg.1

.include <bsd.port.pre.mk>

.if !defined(WITH_MPG321)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to use mpg321 instead of mpg123,"
	@${ECHO_MSG} "hit Ctrl-C right now and execute \"make WITH_MPG321=yes\""
	@${ECHO_MSG}
.endif

.if defined(WITH_MPG321)
post-patch:
	@${REINPLACE_CMD} -E -e \
		's/^(#define MPG123_BINARY "mpg)123"/\1321"/' \
		${WRKSRC}/src/io_mpg123.c
.endif

.include <bsd.port.post.mk>
