# New ports collection makefile for: imanager
# Version required:	2.0
# Date created:		18 March 2000
# Whom:			Cliff Rowley <dozprompt@onsea.com>
#
# $FreeBSD$
#

DISTNAME=	imanager-2.0.final.imlib
PKGNAME=	imanager-2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.digidezign.com/~imanager/

MAINTAINER=	dozprompt@onsea.com

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}"
MAKE_ENV+=	KDEDIR="${LOCALBASE}"

.include <bsd.port.mk>
