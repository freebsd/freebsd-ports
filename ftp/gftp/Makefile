# New ports collection makefile for:	gftp
# Version required:	1.13
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $Id: Makefile,v 1.1.1.1 1999/04/03 01:38:52 steve Exp $
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

pre-install:
	find ${WRKSRC} -name \*.orig -exec ${RM} -f \{} \;

.include <bsd.port.mk>
