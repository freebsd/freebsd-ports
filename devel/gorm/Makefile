# New ports collection makefile for:    Gorm
# Date created:         15 Mar 2002
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gorm
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
DISTNAME=	Gorm-${PORTVERSION}
MASTER_SITE_SUBDIR=	dev-apps

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical Object Relationship Modeller

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
USE_GMAKE=	yes
MAKEFILE=	
ALL_TARGET=

.include <bsd.port.pre.mk>

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

.if defined(WITH_GNUSTEP_DEVEL)
PLIST_SUB+=	PALETTES=System/Applications/Gorm.app/Resources
.else
PLIST_SUB+=	PALETTES=System/Developer/Palettes
.endif

.include <bsd.port.post.mk>
