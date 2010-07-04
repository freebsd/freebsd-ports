# New ports collection makefile for:	py-postgresql
# Date created:				15 August 2009
# Whom:					Volodymyr Kostyrko <c.kworr@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	1.0.1
CATEGORIES=	databases python
MASTER_SITES=	http://python.projects.postgresql.org/files/ \
		http://limbo.xim.bz/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Python 3 compatible PostgreSQL database driver and tools

USE_BZIP2=	yes
USE_PGSQL=	yes
USE_PYTHON=	3.1+
USE_PYDISTUTILS=	yes

PYDISTUTILS_EGGINFO=	py_${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info

.include <bsd.port.mk>
