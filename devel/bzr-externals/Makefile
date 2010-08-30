# New ports collection makefile for:	bzr-externals
# Date created:				2010-08-30
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-externals
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/54615635/ \
		http://www.c-s.li/ports/
DISTNAME=	externals-${PORTVERSION}

MAINTAINER=	c-s@c-s.li
COMMENT=	Support external branches like svn:externals

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/externals

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
