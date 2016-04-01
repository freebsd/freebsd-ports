# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	herrie
PORTVERSION=	2.2
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://herrie.info/distfiles/ \
		http://www.stack.nl/~ed/projects/herrie/distfiles/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Small command line interface music player

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=verbose
CONFIGURE_ENV+=	PREFIX=${PREFIX}

USES=		pkgconfig tar:bzip2
USE_GNOME=	glib20

OPTIONS_DEFINE=	MAD VORBIS SNDFILE MODPLUG HTTP LIBAO XCURSES XSPF NLS
OPTIONS_DEFAULT=	MAD VORBIS HTTP XSPF
OPTIONS_SUB=	yes

HTTP_DESC=	HTTP streams and AudioScrobbler support
LIBAO_DESC=	LibAO support (breaks chroot)
XCURSES_DESC=	Build XCurses version

MAD_LIB_DEPENDS=	libmad.so:audio/libmad \
			libid3tag.so:audio/libid3tag
MAD_CONFIGURE_OFF=no_mp3
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_OFF=no_vorbis
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_OFF=no_sndfile
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CFLAGS=		-I${LOCALBASE}/include/libmodplug
MODPLUG_CONFIGURE_OFF=no_modplug
HTTP_LIB_DEPENDS=	libcurl.so:ftp/curl
HTTP_CONFIGURE_OFF=no_http no_scrobbler
LIBAO_LIB_DEPENDS=	libao.so:audio/libao
LIBAO_CONFIGURE_ON=ao
XCURSES_LIB_DEPENDS=	libXCurses.so:devel/pdcurses
XCURSES_CONFIGURE_ON=xcurses
XSPF_LIB_DEPENDS=	libxspf.so:multimedia/libxspf
XSPF_CONFIGURE_OFF=no_xspf
NLS_USES=	gettext
NLS_CONFIGURE_OFF=no_nls

.include <bsd.port.mk>
