# New ports collection makefile for:   asmodem
# Version required:    0.6
# Date created:        11 May 1998
# Whom:                Sean Cole <scole@aracnet.com>
#
# $Id$
#

DISTNAME=       asmodem-0.6
CATEGORIES=     comms x11
MASTER_SITES=   ftp://afterstep.foo.net/pub/AfterStep/apps/asmodem/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/afterstep/apps/asmodem/

MAINTAINER=     ports@FreeBSD.ORG

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=      yes
USE_IMAKE=	yes

post-install:
		strip ${PREFIX}/bin/asmodem

.include <bsd.port.mk>
