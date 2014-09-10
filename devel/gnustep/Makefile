# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep
PORTVERSION=	1.28.0
PORTREVISION=	2
CATEGORIES=	devel lang gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Objective-C libraries based on the OpenStep standard

# Backends are slave ports with conflicting plists
WITH_GNUSTEP_SINGLE_BACKEND=yes

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CAIRO=	yes

.include <bsd.port.mk>
