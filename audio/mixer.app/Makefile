# New ports collection makefile for:  	mixer.app
# Version required:	1.4.0
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.4 1999/05/05 13:50:15 flathill Exp $
#

DISTNAME=	Mixer.app-1.4.0
PKGNAME=	mixer.app-1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.student.hk-r.se/~pt96pli/mixer/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
