# New ports collection makefile for:	gqmpeg
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqmpeg
PORTVERSION=	0.20.0
PORTEPOCH=	1
CATEGORIES+=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	lyngbol@wheel.dk
COMMENT?=	Another gtk-based MP3 frontend

RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools \
		xmp:${PORTSDIR}/audio/xmp

.if defined(WITH_MPG321)
RUN_DEPENDS+=	mpg321:${PORTSDIR}/audio/mpg321
.else
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
WANT_GNOME=	yes
USE_LIBTOOL_VER=	13
USE_AUTOCONF_VER=	213

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

MAN1=		gqmpeg.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX=	-gnome
CONFIGURE_ENV+=	USE_GNOME="yes"
PLIST_SUB+=	DATADIR="share/gnome"
.else
CONFIGURE_ENV+=	USE_GNOME=""
PLIST_SUB+=	DATADIR="share"
.endif

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
