# New ports collection makefile for:	host
# Date created:				29 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	host
PORTVERSION=	991529
CATEGORIES=	dns
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An utility to query DNS servers

CONFLICTS=	bind-8.* bind84-8.* bind9-9.* bind9-dlz-* bind9-sdb-mysql-* skalibs-*
NO_WRKSUBDIR=	yes

MAN1=		host.1
PLIST_FILES=	bin/host

.include <bsd.port.mk>
