# New ports collection makefile for:  	mixer.app
# Version required:	1.4.1
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.5 1999/05/10 04:06:57 steve Exp $
#

DISTNAME=	Mixer.app-1.4.1
PKGNAME=	mixer.app-1.4.1
CATEGORIES=	audio
MASTER_SITES=	http://www.student.hk-r.se/~pt96pli/mixer/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
