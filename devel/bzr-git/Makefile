# Ports collection makefile for:	bzr-git
# Date created:		9 August 2010
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-git
PORTVERSION=	0.5.2
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/52765000/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Plugin for bzr to work with git trees

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dulwich/__init__.py:${PORTSDIR}/devel/dulwich \
		bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_git

.include <bsd.port.mk>
