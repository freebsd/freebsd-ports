# Ports collection makefile for:	bzr-rewrite
# Date created:				2010-11-10
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-rewrite
PORTVERSION=	0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/94574861/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A bzr plugin that provides rewriting existing revisions

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_rewrite

.include <bsd.port.mk>
