# New ports collection makefile for:    gnustep-objc
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-objc
PORTVERSION=	1.3.0
PORTEPOCH=	1
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A snapshot of libobjc, meant to be used with GNUstep

PREFIX=		${LOCALBASE}/GNUstep
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
GNUSTEP_WITHOUT_LIBOBJC=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
NO_MTREE=	yes
INSTALLS_SHLIB=	yes
NOT_FOR_ARCHS=	ia64 amd64

.include <bsd.port.mk>
