# New ports collection makefile for:	dnsproxy
# Date created:				14 January 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dnsproxy
PORTVERSION=	1.13
CATEGORIES=	dns
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A proxy for DNS queries

GNU_CONFIGURE=	YES

MAN1=		dnsproxy.1
PLIST_FILES=	sbin/dnsproxy

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dnsproxy ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/dnsproxy.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
