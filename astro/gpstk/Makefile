# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpstk
PORTVERSION=	2.5
CATEGORIES=	astro devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing GPS applications

LICENSE=	LGPL3

USES=		cmake python:run
USE_GCC=	yes
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude .git

WRKSRC=		${WRKDIR}/dev

.include <bsd.port.mk>
