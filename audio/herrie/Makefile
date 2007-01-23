# New ports collection makefile for:	herrie
# Date created:				01 August 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	herrie
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://g-rave.nl/projects/herrie/distfiles/ \
		http://www.il.fontys.nl/~ed/projects/herrie/distfiles/ \
		http://www.stack.nl/~ed/projects/herrie/distfiles/

MAINTAINER=	ed@fxq.nl
COMMENT=	A small command line interface music player

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_OPENSSL=	yes
USE_GNOME=	glib20
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

OPTIONS=	MAD "MAD MP3 support" on \
		VORBIS "Ogg Vorbis support" on \
		SNDFILE "libsndfile support" on \
		LIBAO "LibAO support (breaks chroot)" off \
		XCURSES "Build XCurses version" off

PLIST_FILES=	bin/herrie \
		share/locale/nl/LC_MESSAGES/herrie.mo
MAN1=		herrie.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/mad \
		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
MAKE_ENV+=	NO_MP3=yes
.endif
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.else
MAKE_ENV+=	NO_VORBIS=yes
.endif
.if !defined(WITHOUT_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.else
MAKE_ENV+=	NO_SNDFILE=yes
.endif
.if !defined(WITHOUT_LIBAO)
LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao
MAKE_ARGS+=	AUDIO_OUTPUT=ao
.endif
.if !defined(WITHOUT_XCURSES)
LIB_DEPENDS=	XCurses.2:${PORTSDIR}/devel/pdcurses
MAKE_ARGS+=	XCURSES=yes
.endif

.include <bsd.port.post.mk>
