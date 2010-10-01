# New ports collection makefile for:	mp3-archive-tools
# Date created:		2010-07-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	mp3-archive-tools
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://erislabs.net/ianb/projects/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A set of tools to ease organising a collection of audio files

BUILD_DEPENDS=	${SITE_PERL}/MP3/Archive.pm:${PORTSDIR}/audio/libmp3-archive-perl \
		${SITE_PERL}/MP3/Tag.pm:${PORTSDIR}/audio/p5-MP3-Tag
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		cddbtofilename.1 filenametoid3.1 freedbtofilename.1 \
		id3tofilename.1 movemusic.1 mp3-archive-tools.1 mp3id.1 \
		pmv.1 update-music-symlinks.1

.include <bsd.port.mk>
