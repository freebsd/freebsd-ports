# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	herrie
PORTVERSION=	2.2
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://herrie.info/distfiles/ \
		http://www.stack.nl/~ed/projects/herrie/distfiles/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	A small command line interface music player

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=verbose
CONFIGURE_ENV+=	PREFIX=${PREFIX}

USE_BZIP2=	yes
USE_GNOME=	glib20

OPTIONS_DEFINE=	MAD VORBIS SNDFILE MODPLUG HTTP LIBAO XCURSES XSPF
OPTIONS_DEFAULT=	MAD VORBIS HTTP XSPF

HTTP_DESC=	HTTP streams and AudioScrobbler support
LIBAO_DESC=	LibAO support (breaks chroot)
XCURSES_DESC=	Build XCurses version

MAN1=		herrie.1
MANCOMPRESSED=	yes

.include <bsd.port.options.mk>

.if ${OSVERSION} < 700033
CONFIGURE_ARGS+=ncurses
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/mad \
		id3tag:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=no_mp3
.endif
.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=no_vorbis
.endif
.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=no_sndfile
.endif
.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
.else
CONFIGURE_ARGS+=no_modplug
.endif
.if ${PORT_OPTIONS:MHTTP}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=no_http no_scrobbler
.endif
.if ${PORT_OPTIONS:MLIBAO}
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=ao
.endif
.if ${PORT_OPTIONS:MXCURSES}
LIB_DEPENDS+=	XCurses:${PORTSDIR}/devel/pdcurses
CONFIGURE_ARGS+=xcurses
.endif
.if ${PORT_OPTIONS:MXSPF}
LIB_DEPENDS+=	xspf:${PORTSDIR}/multimedia/libxspf
.else
CONFIGURE_ARGS+=no_xspf
.endif
.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=no_nls
.endif

.include <bsd.port.mk>
