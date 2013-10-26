# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	ctris
PORTVERSION=	0.42
CATEGORIES=	games
MASTER_SITES=	http://www.hackl.dhs.org/data/download/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Colorized, small, and flexible Tetris(TM)-clone for the console

LICENSE=	GPLv2

USE_BZIP2=	yes

PLIST_FILES=	bin/ctris man/man6/ctris.6.gz

post-patch:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" -e "s|CFLAGS=.*|CFLAGS+=-Wall|" \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/ctris.6.gz \
		${STAGEDIR}${PREFIX}/man/man6/ctris.6.gz
	${INSTALL_PROGRAM} ${WRKSRC}/ctris ${STAGEDIR}${PREFIX}/bin/ctris

.include <bsd.port.mk>
