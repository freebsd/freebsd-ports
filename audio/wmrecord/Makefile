# New ports collection makefile for:   wmrecord
# Date created:        2 April 2001
# Whom:                Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmrecord
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://linkinnovations.linux.tucows.com/files/x11/dock/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose audio recording utility for the WindowMaker dock

USE_XORG=	xpm x11 xext
MAKE_ARGS=	LIBS="-L${LOCALBASE}/lib -lXpm -lX11 -lXext" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBDIR=""

MAN1=		wmrecord.1
PLIST_FILES=	bin/wmrecord

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmrecord ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/wmrecord.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
