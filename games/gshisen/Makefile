# New ports collection makefile for:    GShisen
# Date created:         12 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gshisen
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	games gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gshisen/ \
		${MASTER_SITE_GNUSTEP_CH}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Shisen-sho puzzle game for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|)/Makefiles|)/Library/Makefiles|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
