# New ports collection makefile for:    charmap
# Date created:         28 Aug 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	charmap
PORTVERSION=	0.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.nongnu.org/charmap/ \
		http://io.debian.net/~tar/ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Character map for GNUstep

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
