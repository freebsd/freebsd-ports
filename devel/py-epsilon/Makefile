# New ports collection makefile for:	py-epsilon
# Date created:				10 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	epsilon
PORTVERSION=	0.5.12
CATEGORIES=	devel python
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Epsilon is a set of Python utility modules used by DivMod projects

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

MAKE_JOBS_SAFE=  yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Epsilon
PYDISTUTILS_EGGINFO=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}_r17222-${PYTHON_VERSION:S/thon//}.egg-info
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
