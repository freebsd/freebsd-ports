# New ports collection makefile for:	libevent
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	libevent
PORTVERSION=	0.7.c
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.c$/c/}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Provides an API to execute callback functions on certain events

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN3=	event.3
MLINKS=	event.3 event_init.3 event.3 event_dispatch.3 event.3 event_set.3 \
	event.3 event_add.3 event.3 event_del.3 event.3 event_pending.3 \
	event.3 event_loop.3 event.3 event_initalized.3 \
	event.3 evtimer_set.3 event.3 evtimer_add.3 event.3 evtimer_del.3 \
	event.3 evtimer_pending.3 event.3 evtimer_initialized.3 \
	event.3 signal_set.3 event.3 signal_add.3 event.3 signal_del.3 \
	event.3 signal_pending.3 event.3 signal_initialized.3

do-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=,' -e 's,-O2,,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
