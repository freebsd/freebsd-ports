# New ports collection makefile for:	libitl
# Date created:				January 12 2005
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	libitl
PORTVERSION=	0.6.3
CATEGORIES=	arabic
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arabeyes

MAINTAINER=	samy@kerneled.org
COMMENT=	An API abstraction to common Islamic calculations

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/itl

WRKSRC=		${WRKDIR}/itl/libs-${PORTVERSION}

.include <bsd.port.mk>
