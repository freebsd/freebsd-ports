# New ports collection makefile for:	gtimer
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtimer
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.radix.net/~cknudsen/gtimer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A timer for your personal activities

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=		gtimer.1

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g' \
		${WRKSRC}/project.c

post-install:
	@${INSTALL_MAN} ${WRKSRC}/gtimer.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
