# New ports collection makefile for:  	mixer.app
# Version required:	1.4.1
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Mixer.app-1.4.1
PKGNAME=	mixer.app-1.4.1
CATEGORIES=	audio
MASTER_SITES=	http://www.student.hk-r.se/~pt96pli/mixer/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
