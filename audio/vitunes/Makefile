# New ports collection makefile for:	vitunes
# Date created:		2009-09-02
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vitunes
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.vitunes.org/files/ \
		http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A curses-based media player with vim-like keybinds

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

ALL_TARGET=	vitunes
PLIST_FILES=	bin/vitunes
MAN1=	vitunes.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '26d' ${WRKSRC}/vitunes.h

.include <bsd.port.mk>
