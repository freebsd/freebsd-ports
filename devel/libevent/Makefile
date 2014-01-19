# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	libevent
PORTVERSION=	1.4.14b
PORTREVISION?=	3
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/
DISTNAME=	${PORTNAME}-${DISTVERSION}-stable

MAINTAINER=	mm@FreeBSD.org
COMMENT?=	Provides an API to execute callback functions on certain events

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
.if !defined(_BUILDING_LIBEVENT_HIPHOP)
USE_LDCONFIG=	yes
.endif

pre-configure:
	@${MKDIR} ${WRKSRC}/m4

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=,' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/LIBS/s/-lrt//g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/epoll.c ${WRKSRC}/epoll_sub.c ${WRKSRC}/evdns.c

regression-test: build
	@(${SH} ${WRKSRC}/test/regress)

.include <bsd.port.mk>
