# New ports collection Makefile for:	libsock
# Date created:		22 August 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	libsock
PORTVERSION=	1.2.0
CATEGORIES=	devel
DISTNAME=	canonware-1.2.0
MASTER_SITES=	http://www.canonware.com/download/canonware/

MAINTAINER=	jasone@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook \
		${LOCALBASE}/lib/libstash.a:${PORTSDIR}/devel/libstash

GNU_CONFIGURE=	yes

MAN3= libsock.3s libsock_sock.3s libsock_socks.3s
MANCOMPRESSED=	no

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook libsock)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook libsock_install)

.include <bsd.port.mk>
