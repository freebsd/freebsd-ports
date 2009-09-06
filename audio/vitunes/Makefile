# New ports collection makefile for:	vitunes
# Date created:		2009-09-02
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vitunes
PORTVERSION=	0.93
CATEGORIES=	audio
MASTER_SITES=	http://www.ryanflannery.net/hacking/vitunes/files/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A curses-based media player with vim-like keybinds

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

WRKSRC=	${WRKDIR}/${PORTNAME}

ALL_TARGET=	vitunes
PLIST_FILES=	bin/vitunes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
