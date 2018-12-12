# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://python.projects.postgresql.org/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Python 3 compatible PostgreSQL database driver and tools

LICENSE=	BSD3CLAUSE

USES=		zip pgsql python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
