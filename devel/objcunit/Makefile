# New ports collection makefile for:    objcunit
# Date created:         21 Jan 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	objcunit
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://xanthippe.dyndns.org/Zipper/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	ObjcUnit-${PORTVERSION}-GNUstep

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	ObjcUnit frammework for GNUstep

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/ObjcUnit-${PORTVERSION}/ObjcUnit
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=

.include <bsd.port.mk>
