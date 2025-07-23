PORTNAME=	libmp3splt
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	citrin@citrin.ru
COMMENT=	Library for splitting of various audio files
WWW=		https://mp3splt.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cutter --disable-doxygen_doc
USES=		cpe libtool pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CPE_VENDOR=	libmp3splt_project

OPTIONS_MULTI=	PLUGIN
OPTIONS_MULTI_PLUGIN=	MAD FLAC VORBIS
OPTIONS_DEFINE=	ID3 PCRE NLS
OPTIONS_SUB=	yes

PCRE_DESC=	PCRE support to set tags from input filename

OPTIONS_DEFAULT=	MAD FLAC VORBIS ID3 PCRE

MAD_CONFIGURE_ENABLE=	mp3
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

FLAC_CONFIGURE_ENABLE=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

VORBIS_CONFIGURE_ENABLE=ogg
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis

PCRE_CONFIGURE_ENABLE=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

ID3_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3_CONFIGURE_ENABLE=	id3tag

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
