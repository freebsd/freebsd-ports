# Ports collection makefile for:  dnsutl
# Version required:     	  1.3
# Date created:			  Nov 05, 1998
# Whom:				  Karl Dietz (Karl.Dietz@triplan.com)
#
# $Id: Makefile,v 1.4 1998/08/20 22:06:00 obrien Exp $
#

DISTNAME=	dnsutl.1.3
PKGNAME=	dnsutl-1.3
CATEGORIES=	net
MASTER_SITES=	http://www.tip.net.au/~millerp/  \
				http://gd.tuwien.ac.at/softeng/Aegis/

MAINTAINER=	Karl.Dietz@triplan.com

HAS_CONFIGURE=	yes
CONFIGURE_PARAM=	--prefix=${PREFIX}
CONFIGURE_ENV=	LIBS=-lcompat
ALL_TARGET=	all sure
INSTALL_TARGET=	install-bin

MAN1=		dns-bootp.1 dns-ethers.1 dns-hosts.1 dns-rev.1 \
		dns-bootprms.1 dns-filter.1 dns-ng.1

post-install:
	cd ${WRKSRC}/man1 ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
