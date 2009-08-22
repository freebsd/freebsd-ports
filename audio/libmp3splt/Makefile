# New ports collection makefile for:	libmp3splt
# Date created:		2009-03-26
# Whom:			Anton Yuzhaninov <citrin@citrin.ru>
#
# $FreeBSD$
#

PORTNAME=	libmp3splt
PORTVERSION=	0.5.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Library for mp3splt and mp3splt-gtk

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libltdl

OPTIONS=	MP3	"mp3 support"	on \
		ID3	"id3tag support for the mp3"	on \
		VORBIS	"ogg vorbis support"	on

PLIST_DIRS=	include/libmp3splt lib/libmp3splt
PLIST_FILES=	include/libmp3splt/mp3splt.h lib/libmp3splt.so.0 \
		lib/libmp3splt.so lib/libmp3splt.la lib/libmp3splt.a

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MP3) && defined(WITHOUT_VORBIS)
IGNORE=	select at least one plugin: mp3 or vorbis
.endif

.if defined(WITHOUT_MP3)
CONFIGURE_ARGS+=	--disable-mp3
.else
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
PLIST_FILES+=	lib/libmp3splt/libsplt_mp3.a \
		lib/libmp3splt/libsplt_mp3.la \
		lib/libmp3splt/libsplt_mp3.so \
		lib/libmp3splt/libsplt_mp3.so.0
.endif

.if defined(WITHOUT_ID3)
CONFIGURE_ARGS+=	--disable-id3tag
.else
LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--disable-ogg
.else
LIB_DEPENDS+=	ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/libmp3splt/libsplt_ogg.a \
		lib/libmp3splt/libsplt_ogg.la \
		lib/libmp3splt/libsplt_ogg.so \
		lib/libmp3splt/libsplt_ogg.so.0
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.post.mk>
