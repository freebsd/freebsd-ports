# New ports collection makefile for:	xmms-curses
# Date created:				2007-07-20
# Whom:				Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-curses
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A ncurses program for (remote) controlling multimedia/xmms

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

MAN1=	${PORTNAME}.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -lncurses `xmms-config --cflags --libs` -o xmms-curses *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmms-curses ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA}	${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc
.endif

.include <bsd.port.mk>
