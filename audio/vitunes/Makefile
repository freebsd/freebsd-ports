# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vitunes
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://vitunes.org/files/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A curses-based media player with vim-like keybinds

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

NO_STAGE=	yes
ALL_TARGET=	vitunes
PLIST_FILES=	bin/vitunes
MAN1=	vitunes.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '27d' ${WRKSRC}/vitunes.h

.include <bsd.port.mk>
