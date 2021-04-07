PORTNAME=	pymssql
PORTVERSION=	2.1.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@thelanman.net
COMMENT=	Python database interface for MS-SQL. Version 2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>0:devel/py-setuptools-git@${PY_FLAVOR}
LIB_DEPENDS=	libsybdb.so:databases/freetds

USES=		python:3.6+
USE_PYTHON=	autoplist distutils cython

post-extract:
	@${RM} ${WRKSRC}/_mssql.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_mssql*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pymssql*.so

.include <bsd.port.mk>
