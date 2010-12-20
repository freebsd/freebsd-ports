# Ports collection makefile for:	bzr-upload
# Date created:				2010-12-11
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-upload
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/60433187/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Bzr plugin to incrementally upload changes to a dumb server

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_upload

.include <bsd.port.mk>
