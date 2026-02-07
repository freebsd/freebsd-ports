PORTNAME=	agate-sql
PORTVERSION=	0.7.3
CATEGORIES=	databases textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Add SQL read/write support to agate
WWW=		https://agate-sql.rtfd.org/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.0:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
