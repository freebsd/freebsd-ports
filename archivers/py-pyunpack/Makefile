PORTNAME=	pyunpack
PORTVERSION=	0.3
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	unpack archive files in Python
WWW=		https://github.com/ponty/pyunpack

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoint2>0:devel/py-entrypoint2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
