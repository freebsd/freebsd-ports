# Ports collection makefile for:	bzr-pipeline
# Date created:				2010-11-16
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-pipeline
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/90476867/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Bzr tools for working with a sequence of branches

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BzrPipeline
WRKSRC=			${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
