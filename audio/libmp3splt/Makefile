# Created by: Anton Yuzhaninov <citrin@citrin.ru>
# $FreeBSD$

PORTNAME=	libmp3splt
PORTVERSION=	0.9.2
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Library for splitting of various audio files

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cutter --disable-doxygen_doc
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_MULTI=	plugin
OPTIONS_MULTI_plugin=	MAD FLAC VORBIS
OPTIONS_DEFINE=	ID3 PCRE NLS
OPTIONS_SUB=	yes

PCRE_DESC=	PCRE support to set tags from input filename

OPTIONS_DEFAULT=	MAD FLAC VORBIS ID3 PCRE NLS

MAD_CONFIGURE_ENABLE=	mp3
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

FLAC_CONFIGURE_ENABLE=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

VORBIS_CONFIGURE_ENABLE=ogg
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis

PCRE_CONFIGURE_ENABLE=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

MID3_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
MID3_CONFIGURE_ENABLE=	id3tag

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
