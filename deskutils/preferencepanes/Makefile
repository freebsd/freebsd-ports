# New ports collection makefile for:    preferencepanes
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	preferencepanes
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/system-preferences/
DISTNAME=	systempreferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PreferencePanes framework for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
DEFAULT_LIBVERSION=	1.0.0
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

WRKSRC=		${WRKDIR}/${DISTNAME}/PreferencePanes

.include <bsd.port.mk>
