# Ports collection makefile for:	bzr-rewrite
# Date created:				2010-11-10
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-rewrite
PORTVERSION=	0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/53456671/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	A bzr plugin that provides rewriting existing revisions

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_rewrite

.include <bsd.port.mk>
