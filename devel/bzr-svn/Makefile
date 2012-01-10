# Ports collection makefile for:	bzr-svn
# Date created:				8 August 2010
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-svn
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/87227703/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Plugin for bzr to work with svn

LICENSE=	GPLv2

BUILD_DEPENDS+=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/subvertpy/__init__.py:${PORTSDIR}/devel/py-subvertpy \
		bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_svn

.include <bsd.port.mk>
