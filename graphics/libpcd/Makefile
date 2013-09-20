# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpcd
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/libpcd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for reading PhotoCD images

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/GNUmakefile
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
