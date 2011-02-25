# Ports collection makefile for:	bzr-svn
# Date created:				8 August 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-svn
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/54612267/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Plugin for bzr to work with svn

BUILD_DEPENDS+=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/subvertpy/__init__.py:${PORTSDIR}/devel/py-subvertpy \
		bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_svn

.include <bsd.port.mk>
