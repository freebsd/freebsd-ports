# Created by: Erik Cederstrand <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmmix
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://ftp.twaren.net/BSD/OpenBSD/distfiles/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif-based audio mixer

WRKSRC=		${WRKDIR}/xmmix-1.2

USES=		imake motif xorg
USE_XORG=	x11 xext sm ice xt

PLIST_FILES=	bin/xmmix lib/X11/app-defaults/XMmix lib/X11/xmmix.hlp \
		man/man1/xmmix.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/XMmix.ad

.include <bsd.port.mk>
