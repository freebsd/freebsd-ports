# New ports collection makefile for:	netris
# Version required:	0.5
# Date created:	1 August 1996
# Whom:	desmo
#
# $FreeBSD$
#

DISTNAME=		netris-0.5
CATEGORIES=		games ipv6
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

PATCH_SITES=		ftp://ftp2.v6.linux.or.jp/pub/Linux/IPv6-2/netris/ \
			http://ftp2.v6.linux.or.jp/pub/Linux/IPv6-2/netris/
PATCHFILES=		netris-0.5-v6-19991206a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		desmo@bandwidth.org

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
MAN1=			netris.1

post-install:
	${INSTALL_MAN} ${FILESDIR}/netris.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
