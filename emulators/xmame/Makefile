# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmame
PORTVERSION=	0.36b3.1
CATEGORIES=	emulators
MASTER_SITES=	http://xmame.retrogames.com/download/ \
		ftp://ftp.kaupp.cx/pub/xmame/ \
		ftp://ftp.bingo-ev.de/pub/software/emulator/
EXTRACT_SUFX=	.tgz

MAINTAINER=     dburr@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	YES
MAKEFILE=	makefile.unix

MAN6=		xmame.6

post-install:
	${MKDIR} ${PREFIX}/lib/xmame ${PREFIX}/lib/xmame/doc ${PREFIX}/lib/xmame/hi ${PREFIX}/lib/xmame/roms
	${CHMOD} 777 ${PREFIX}/lib/xmame/hi
	for file in cheat.dat history.dat README.unix gamelist.txt; do ${INSTALL} -C -o root -g wheel -m 444 ${WRKSRC}/doc/$${file} ${PREFIX}/lib/xmame/$${file}; done
	${INSTALL} -C -o root -g wheel -m 644 ${WRKSRC}/doc/xmamerc.dist ${PREFIX}/lib/xmame/xmamerc
	for file in Changes LEEME.unix MailList.notes README.fx README.xgl TODO cheat.doc credits.unix liesmich.unix multiplayer-readme.txt readme.dos whatsnew.txt; do ${INSTALL} -C -o root -g wheel -m 444 ${WRKSRC}/doc/$${file} ${PREFIX}/lib/xmame/doc/$${file}; done

.include <bsd.port.mk>
