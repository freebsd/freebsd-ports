# New ports collection makefile for:	bzr-externals
# Date created:				2010-08-30
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-externals
PORTVERSION=	1.3.3
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/91495699/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Support external branches like svn:externals

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC=		${WRKDIR}/externals

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
