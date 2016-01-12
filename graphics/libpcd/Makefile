# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpcd
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/libpcd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading PhotoCD images

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USES=		gmake
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpcd.so

.include <bsd.port.mk>
