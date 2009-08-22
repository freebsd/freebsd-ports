# New ports collection makefile for:	libitl
# Date created:				January 12 2005
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	libitl
PORTVERSION=	0.6.3
CATEGORIES=	arabic
MASTER_SITES=	SF/arabeyes/ITL%20Library%20%28${PORTNAME}%29/lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An API abstraction to common Islamic calculations

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/itl

WRKSRC=		${WRKDIR}/itl/libs-${PORTVERSION}

.include <bsd.port.mk>
