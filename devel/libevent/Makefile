# New ports collection makefile for:	libevent
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	libevent
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes

MAN3=	event.3
MLINKS=	event.3 event_init.3 event.3 event_dispatch.3 event.3 event_set.3 \
	event.3 event_add.3 event.3 event_del.3 event.3 event_pending.3 \
	event.3 event_loop.3 event.3 event_initalized.3 \
	event.3 evtimer_set.3 event.3 evtimer_add.3 event.3 evtimer_del.3 \
	event.3 evtimer_pending.3 event.3 evtimer_initialized.3 \
	event.3 signal_set.3 event.3 signal_add.3 event.3 signal_del.3 \
	event.3 signal_pending.3 event.3 signal_initialized.3

post-patch:
	@${RM} ${WRKSRC}/compat/sys/time.h

# install target strangely broken
do-install:
	${INSTALL_DATA} ${WRKSRC}/event.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libevent.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/event.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
