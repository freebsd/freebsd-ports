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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
USE_GMAKE=	YES
USE_BZIP2=	YES
MAN1=		gtimer.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/gtimer.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
