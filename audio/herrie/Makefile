# New ports collection makefile for:	herrie
# Date created:				01 August 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	herrie
PORTVERSION=	2.2
PORTREVISION=	7
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

OPTIONS=	MAD "MAD MP3 support" on \
		VORBIS "Ogg Vorbis support" on \
		SNDFILE "libsndfile support" off \
		MODPLUG "libmodplug support" off \
		HTTP "HTTP streams and AudioScrobbler support" on \
		LIBAO "LibAO support (breaks chroot)" off \
		XCURSES "Build XCurses version" off \
		XSPF "Support for XSPF playlists" on

MAN1=		herrie.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
CONFIGURE_ARGS+=ncurses
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/mad \
		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=no_mp3
.endif
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=no_vorbis
.endif
.if !defined(WITHOUT_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=no_sndfile
.endif
.if !defined(WITHOUT_MODPLUG)
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
.else
CONFIGURE_ARGS+=no_modplug
.endif
.if !defined(WITHOUT_HTTP)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=no_http no_scrobbler
.endif
.if !defined(WITHOUT_LIBAO)
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=ao
.endif
.if !defined(WITHOUT_XCURSES)
LIB_DEPENDS+=	XCurses.2:${PORTSDIR}/devel/pdcurses
CONFIGURE_ARGS+=xcurses
.endif
.if !defined(WITHOUT_XSPF)
LIB_DEPENDS+=	xspf.4:${PORTSDIR}/multimedia/libxspf
.else
CONFIGURE_ARGS+=no_xspf
.endif
.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=no_nls
.endif

.include <bsd.port.post.mk>
