PORTNAME=	postgresql
PORTVERSION=	1.3.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	arcade@b1t.name
COMMENT=	Python 3 compatible PostgreSQL database driver and tools
WWW=		https://github.com/python-postgres/fe

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pgsql python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/postgresql -name '*.so' \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
