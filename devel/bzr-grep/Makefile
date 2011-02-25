# Ports collection makefile for:	bzr-grep
# Date created:				9 Jun 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-grep
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/49936719/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Bazaar plugin to grep files

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_grep
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.final.0

.include <bsd.port.mk>
