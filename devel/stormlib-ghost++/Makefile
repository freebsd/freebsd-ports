# New ports collection makefile for:	stormlib
# Date created:		2011-02-13
# Whom:			 <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	stormlib
PORTVERSION=	6.25
CATEGORIES=	devel archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ghost++
DISTNAME=	${PROJECTHOST}_${PROJECTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to read and write MPQ archives

PROJECTHOST=	ghostplusplus
PROJECTVERSION=	17.1

USE_ZIP=	yes
USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/ghost/StormLib/stormlib

USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
