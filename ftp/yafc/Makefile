# New ports collection makefile for:	yafc
# Version required:	0.4.7
# Date created:		10 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	yafc-0.4.7
CATEGORIES=	ftp
MASTER_SITES=	ftp://mayer.physto.se/pub/yafc/

MAINTAINER=	cpiazza@FreeBSD.org

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

MAN1=		yafc.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/yafc.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
