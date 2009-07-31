# New ports collection makefile for:	bmp-song_change
# Date created:				27 January, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmp-songchange
PORTVERSION=	0.0.2
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/bmp-plugins/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beep Media Player do-this-on-song-change plugin

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

GNU_CONFIGURE=  yes

PLIST_FILES=	lib/bmp/General/libsong_change.so

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.post.mk>
