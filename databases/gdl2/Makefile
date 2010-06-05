# New ports collection makefile for:    gdl2
# Date created:         12 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	gdl2
PORTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	databases gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	gnustep-dl2-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Database Library 2 (Enterprise Objects Framework)

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	Gorm:${GORM_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	Renaissance:${RENAISSANCE_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_PGSQL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes

GORM_PORT?=	devel/gorm
RENAISSANCE_PORT?=	x11-toolkits/renaissance

.include <bsd.port.mk>
