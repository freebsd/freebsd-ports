# New ports collection makefile for:    GShisen
# Date created:         12 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gshisen
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
# not up to date:	http://www.gnustep.it/enrico/gshisen/
MASTER_SITES=	http://www.imago.ro/gshisen/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mahjongg-kind of game that uses the GNUstep toolkit

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/GShisen
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=

.include <bsd.port.mk>
