# New ports collection makefile for:   xfrisk
# Date created:        20 April 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xfrisk
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://tuxick.net/xfrisk/files/
DISTNAME=	XFrisk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-player networked Risk game for X11

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

NO_CDROM=	Possible trademark infringement

NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/XFrisk
USE_GMAKE=	yes

USE_XORG=	x11 xt xaw xmu sm ice
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
