# New ports collection makefile for:	libevent
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	libevent
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN3=	event.3
MLINKS=	event.3 event_init.3 event.3 event_dispatch.3 event.3 event_set.3 \
	event.3 event_add.3 event.3 event_del.3 event.3 event_pending.3 \
	event.3 event_initalized.3 event.3 timeout_set.3 event.3 timeout_add.3 \
	event.3 timeout_del.3 event.3 timeout_pending.3 event.3 \
	timeout_initalized.3

post-patch:
	@${PERL} -pi -e 's!\*\.h!event.h!' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
