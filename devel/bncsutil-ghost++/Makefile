# New ports collection makefile for:	bncsutil
# Date created:		2011-02-13
# Whom:			 <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	bncsutil
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ghost++
DISTNAME=	${PROJECTHOST}_${PROJECTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility library for Battle.net clients in C++

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

PROJECTHOST=	ghostplusplus
PROJECTVERSION=	17.1

USE_ZIP=	yes
USE_DOS2UNIX=	yes
WRKSRC=		${WRKDIR}/ghost/bncsutil/src/bncsutil

USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
