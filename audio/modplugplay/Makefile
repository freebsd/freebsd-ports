# New ports collection makefile for:   modplugplay
# Date created:		3 February 2004
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	modplugplay
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.linuks.mine.nu/modplugplay/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A commandline music mod player using libmodplug

LIB_DEPENDS=	modplug.0:${PORTSDIR}/audio/libmodplug

MAN1=		modplugplay.1
PLIST_FILES=	bin/modplugplay

do-build:
	${CXX} ${WRKSRC}/modplugplay.c ${CFLAGS} -o ${WRKSRC}/${PORTNAME} -lmodplug -L${LOCALBASE}/lib -I${LOCALBASE}/include/libmodplug

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
