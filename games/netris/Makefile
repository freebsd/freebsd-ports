# New ports collection makefile for:	netris
# Version required:	0.4
# Date created:	1 August 1996
# Whom:	desmo
#
# $FreeBSD$
#

DISTNAME=		netris-0.4
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

MAINTAINER=		desmo@bandwidth.org

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
MAN1=			netris.1

post-install:
	${INSTALL_MAN} ${FILESDIR}/netris.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
