PORTNAME=	tlv8
PORTVERSION=	0.10.0
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	TLV8 are used to encode arbitrary data
WWW=		https://pypi.org/project/tlv8/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

USES=		python:3.9-3.11 shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
