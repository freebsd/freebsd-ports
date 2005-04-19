# New ports collection makefile for: play
# Date created:		20 May 1998
# Whom:			Masanori Kiriake <seiken@nbs.co.jp>
#
# $FreeBSD$
#

PORTNAME=	play
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PORTS_JP}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple audio file player

CONFLICTS=	sox-[0-9]*

USE_REINPLACE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS}" DESTDIR="${PREFIX}" MANDIR="/man/ja/man"

MANLANG=	ja
MAN1=		play.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/play

post-patch:
.for file in play_audio.c mixer_ctl.c encode_sun.c encode_riff.c speed.c
	@${REINPLACE_CMD} 's,machine/soundcard.h,sys/soundcard.h,' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
