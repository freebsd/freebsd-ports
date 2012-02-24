# Ports collection makefile for:	bzr-git
# Date created:		25 May 2010
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-explorer
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/93535508/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Desktop application for using bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bzrlib/plugins/qbzr/__init__.py:${PORTSDIR}/devel/qbzr \
		bzr:${PORTSDIR}/devel/bazaar-ng

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	explorer
USE_GETTEXT=	yes

.include <bsd.port.mk>
