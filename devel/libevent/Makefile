# New ports collection makefile for:	libevent
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	libevent
PORTVERSION=	1.1a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides an API to execute callback functions on certain events

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN3=	event.3
MLINKS=	event.3 event_init.3 event.3 event_dispatch.3 event.3 event_loop.3 \
	event.3 event_loopexit.3 event.3 event_set.3 event.3 event_add.3 \
	event.3 event_del.3 event.3 event_once.3 event.3 event_pending.3 \
	event.3 event_initialized.3 event.3 event_priority_init.3 \
	event.3 event_priority_set.3 event.3 evtimer_set.3 event.3 evtimer_add.3 \
	event.3 evtimer_del.3 event.3 evtimer_pending.3 event.3 evtimer_initialized.3 \
	event.3 signal_set.3 event.3 signal_add.3 event.3 signal_del.3 \
	event.3 signal_pending.3 event.3 signal_initialized.3 event.3 bufferevent_new.3 \
	event.3 bufferevent_free.3 event.3 bufferevent_write.3 \
	event.3 bufferevent_write_buffer.3 event.3 bufferevent_read.3 \
	event.3 bufferevent_enable.3 event.3 bufferevent_disable.3 \
	event.3 bufferevent_settimeout.3 event.3 evbuffer_new.3 \
	event.3 evbuffer_free.3 event.3 evbuffer_add.3 event.3 evbuffer_add_buffer.3 \
	event.3 evbuffer_add_printf.3 event.3 evbuffer_drain.3 \
	event.3 evbuffer_write.3 event.3 evbuffer_read.3 event.3 evbuffer_find.3

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
