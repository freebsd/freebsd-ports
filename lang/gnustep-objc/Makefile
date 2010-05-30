# New ports collection makefile for:    gnustep-objc
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-objc
PORTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES=	lang devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A snapshot of libobjc, meant to be used with GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
GNUSTEP_WITHOUT_LIBOBJC=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

NOT_FOR_ARCHS=	ia64 amd64

.if !defined(GNUSTEP_WITH_BASE_GCC)
IGNORE=		conflicts: libobjc is used from lang/gcc-objc
.endif

.include <bsd.port.mk>
