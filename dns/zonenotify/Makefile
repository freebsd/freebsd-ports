# New ports collection makefile for:   zonenotify
# Date created:		19 August 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	zonenotify
PORTVERSION=	0.1
CATEGORIES=	dns
MASTER_SITES=	http://morettoni.net/bsd/ \
		http://cvs.delink.net/mirrors/morettoni.net/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A dns notify sender written in C

PLIST_FILES=	bin/zonenotify
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} ${WRKSRC}/zonenotify.c

.include <bsd.port.mk>
