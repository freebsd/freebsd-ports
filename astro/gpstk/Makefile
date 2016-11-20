# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpstk
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	astro devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for developing GPS applications

LICENSE=	LGPL3

USES=		cmake:outsource python:run
USE_GCC=	yes
USE_LDCONFIG=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/dev

EXTRACT_AFTER_ARGS=	--exclude .git

.include <bsd.port.mk>
