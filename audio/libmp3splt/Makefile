# Created by: Anton Yuzhaninov <citrin@citrin.ru>
# $FreeBSD$

PORTNAME=	libmp3splt
DISTVERSION=	0.8.1a
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Library for splitting of various audio files

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libltdl
MAKE_JOBS_SAFE=	yes

OPTIONS_MULTI=	plugin
OPTIONS_MULTI_plugin=	MAD VORBIS
OPTIONS_DEFINE=	ID3 PCRE NLS

PCRE_DESC=	PCRE support to set tags from input filename

OPTIONS_DEFAULT=	MAD VORBIS ID3 PCRE NLS

PLUGIN_DIR=	libmp3splt0

PLIST_DIRS=	include/libmp3splt lib/${PLUGIN_DIR}
PLIST_FILES=	include/libmp3splt/mp3splt.h lib/libmp3splt.a \
		lib/libmp3splt.la lib/libmp3splt.so lib/libmp3splt.so.0 \
		share/aclocal/mp3splt.m4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
PLIST_FILES+=	lib/${PLUGIN_DIR}/libsplt_mp3.a \
		lib/${PLUGIN_DIR}/libsplt_mp3.la \
		lib/${PLUGIN_DIR}/libsplt_mp3.so \
		lib/${PLUGIN_DIR}/libsplt_mp3.so.0
.else
CONFIGURE_ARGS+=	--disable-mp3
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis
PLIST_FILES+=	lib/${PLUGIN_DIR}/libsplt_ogg.a \
		lib/${PLUGIN_DIR}/libsplt_ogg.la \
		lib/${PLUGIN_DIR}/libsplt_ogg.so \
		lib/${PLUGIN_DIR}/libsplt_ogg.so.0
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if ${PORT_OPTIONS:MID3}
LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=	--disable-id3tag
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
LANGUAGES=	de_DE cs es fr_FR hr
.for language in ${LANGUAGES}
PLIST_FILES+=	share/locale/${language}/LC_MESSAGES/libmp3splt0.mo
.endfor
PLIST_FILES+=	"@dirrmtry share/locale/de_DE/LC_MESSAGES"
PLIST_FILES+=	"@dirrmtry share/locale/de_DE"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
