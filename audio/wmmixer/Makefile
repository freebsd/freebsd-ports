# New ports collection makefile for:   wmmixer
# Version required:    1.0b1
# Date created:        11 July 1998
# Whom:                Rich Neswold <rneswold@mcs.net>
#
# $FreeBSD$
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0b1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rneswold@mcs.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=			${WRKDIR}/wmmixer
FETCH_BEFORE_ARGS=	-t
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
