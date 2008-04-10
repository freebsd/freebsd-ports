# New ports collection makefile for:    gdl2
# Date created:         12 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	gdl2
PORTVERSION=	0.11.0
CATEGORIES=	databases gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	gnustep-dl2-${PORTVERSION}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	GNUstep Database Library 2 (Enterprise Objects Framework)

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	Gorm:${GORM_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_PGSQL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes

GORM_PORT?=	devel/gorm

.include <bsd.port.mk>
