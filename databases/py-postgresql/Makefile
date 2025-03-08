PORTNAME=	postgresql
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	arcade@b1t.name
COMMENT=	Python 3 compatible PostgreSQL database driver and tools
WWW=		https://github.com/python-postgres/fe

LICENSE=	BSD3CLAUSE

USES=		pgsql python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
