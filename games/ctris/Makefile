# New ports collection makefile for:	ctetris
# Date created:			14 Aug 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	ctris
PORTVERSION=	0.42
CATEGORIES=	games
MASTER_SITES=	http://www.hackl.dhs.org/data/download/files/ \
		http://www.liquidx.org/distfiles/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Colorized, small, and flexible Tetris(TM)-clone for the console

LICENSE=	GPLv2

USE_BZIP2=	yes
MANCOMPRESSED=	yes

MAN6=		ctris.6
PLIST_FILES=	bin/ctris

post-patch:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" -e "s|CFLAGS=.*|CFLAGS+=-Wall|" \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/ctris.6.gz ${PREFIX}/man/man6/ctris.6.gz
	${INSTALL_PROGRAM} ${WRKSRC}/ctris ${PREFIX}/bin/ctris

.include <bsd.port.mk>
