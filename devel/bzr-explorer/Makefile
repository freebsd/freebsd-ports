# Ports collection makefile for:	bzr-git
# Date created:		25 May 2010
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-explorer
PORTVERSION=	1.1.4
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/74990225/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Desktop application for using bzr

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bzrlib/plugins/qbzr/__init__.py:${PORTSDIR}/devel/qbzr \
		bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	explorer
USE_GETTEXT=	yes

.include <bsd.port.mk>
