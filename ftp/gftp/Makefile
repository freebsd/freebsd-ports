# New ports collection makefile for:	gftp
# Version required:	1.13
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $Id$
#

DISTNAME=	gftp-1.13
CATEGORIES=	net
MASTER_SITES=	http://www.newwave.net/~masneyb/

MAINTAINER=	dmarion@open.hr

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

USE_AUTOCONF=	yes
USE_X_PREFIX=	yes

post-install:
	strip ${PREFIX}/bin/gftp

.include <bsd.port.mk>
