# New ports collection makefile for: imanager
# Date created:		18 March 2000
# Whom:			Cliff Rowley <dozprompt@onsea.com>
#
# $FreeBSD$
#

PORTNAME=	imanager
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxberg.com/files/kde/graphics/
DISTNAME=	imanager-${PORTVERSION}.final.imlib

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_KDELIBS_VER=1
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}"
MAKE_ENV+=	KDEDIR="${LOCALBASE}"

.include <bsd.port.mk>
