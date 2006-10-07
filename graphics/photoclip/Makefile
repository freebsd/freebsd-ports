# New ports collection makefile for:    photoclip
# Date created:         6 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	photoclip
PORTVERSION=	0.2.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.vaisburd.net/PhotoClip/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	PhotoClip-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Simple image viewer and editor for GNUstep

WRKSRC=		${WRKDIR}/PhotoClip
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
