# New ports collection makefile for:  	mixer.app
# Version required:	1.3.1
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	Mixer.app-1.3.1
PKGNAME=	mixer.app-1.3.1
CATEGORIES=	audio
MASTER_SITES=	http://www.student.hk-r.se/~pt96pli/mixer/

MAINTAINER=	cpiazza@home.net

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
