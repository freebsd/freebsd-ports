# New ports collection makefile for:	libpcd
# Date created:		2004-08-23
# Whom:			Andrey Slusar <anray@inet.ua>
#
# $FreeBSD$
#

PORTNAME=	libpcd
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/libpcd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	anray@inet.ua
COMMENT=	A library for reading PhotoCD images

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAKEFILE=	${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
