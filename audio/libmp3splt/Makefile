# New ports collection makefile for:	libmp3splt
# Date created:		2009-03-26
# Whom:			Anton Yuzhaninov <citrin@citrin.ru>
#
# $FreeBSD$
#

PORTNAME=	libmp3splt
PORTVERSION=	0.5.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Library for mp3splt and mp3splt-gtk

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libltdl
MAKE_JOBS_SAFE=	yes

OPTIONS=	MP3	"mp3 support"	on \
		ID3	"id3tag support for the mp3"	on \
		VORBIS	"ogg vorbis support"	on \
		NLS     "native language support"       on

PLIST_DIRS=	include/libmp3splt lib/libmp3splt
PLIST_FILES=	include/libmp3splt/mp3splt.h lib/libmp3splt.so.0 \
		lib/libmp3splt.so lib/libmp3splt.la lib/libmp3splt.a \
		share/aclocal/mp3splt.m4

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

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
LANGUAGES=	de fr
.for language in ${LANGUAGES}
PLIST_FILES+=	share/locale/${language}/LC_MESSAGES/libmp3splt.mo
.endfor
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.post.mk>
