# New ports collection makefile for:	gtimer
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtimer
PORTVERSION=	1.1.5
CATEGORIES=	deskutils
MASTER_SITES=	http://www.radix.net/~cknudsen/gtimer/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

MAN1=		gtimer.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/gtimer.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
