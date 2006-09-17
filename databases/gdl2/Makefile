# New ports collection makefile for:    gdl2
# Date created:         12 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	gdl2
PORTVERSION=	0.10.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	gnustep-dl2-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNUstep Database Library 2 (Enterprise Objects Framework)

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	Gorm:${GORM_PORT}
# broken
# USE_LDCONFIG=	yes
INSTALL_SHLIBS=	yes
MAKEFILE=	GNUmakefile
GORM_PORT?=	devel/gorm
USE_PGSQL=	yes

.include <bsd.port.mk>
