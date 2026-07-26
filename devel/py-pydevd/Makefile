PORTNAME=	pydevd
DISTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Debugger used in PyDev and PyCharm
WWW=		https://pypi.org/project/pydevd/

LICENSE=	APACHE20 EPL
LICENSE_COMB=	dual
LICENSE_FILE_EPL=	${WRKSRC}/LICENSE-EPL

#BUILD_DEPENDS=	${PY_SETUPTOOLS} \
#		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

.include <bsd.port.mk>
