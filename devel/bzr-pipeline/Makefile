# Ports collection makefile for:	bzr-pipeline
# Date created:				2010-11-16
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-pipeline
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/58976607/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Bzr tools for working with a sequence of branches

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/pipeline

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BzrPipeline

.include <bsd.port.mk>
