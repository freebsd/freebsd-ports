PORTNAME=	bincopy
PORTVERSION=	17.14.5
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Mangling of various file formats that conveys binary information
WWW=		https://github.com/eerimoq/bincopy

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}humanfriendly>0:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argparse_addons>=0.4.0:devel/py-argparse_addons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
