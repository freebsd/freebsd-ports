# New ports collection makefile for:  	mixer.app
# Version required:	1.3.1
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/18 19:39:14 mharo Exp $
#

DISTNAME=	Mixer.app-1.3.2
PKGNAME=	mixer.app-1.3.2
CATEGORIES=	audio
MASTER_SITES=	http://www.student.hk-r.se/~pt96pli/mixer/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
