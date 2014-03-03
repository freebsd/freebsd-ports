# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://python.projects.postgresql.org/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Python 3 compatible PostgreSQL database driver and tools

LICENSE=	BSD3CLAUSE

USE_ZIP=		yes
USE_PGSQL=		yes
USE_PYTHON=		3
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
