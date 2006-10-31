# New ports collection makefile for:    preferencepanes
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	preferencepanes
PORTVERSION=	1.0.1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.gnustep.it/enrico/system-preferences/
DISTNAME=	systempreferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PreferencePanes framework for GNUstep

WRKSRC=		${WRKDIR}/${DISTNAME}/PreferencePanes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
DEFAULT_LIBVERSION=	1.0.0

.include <bsd.port.mk>
