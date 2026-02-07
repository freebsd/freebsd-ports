PORTNAME=	tzlocal
DISTVERSION=	5.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	Returns the tzinfo object for the local timezone
WWW=		https://github.com/regebro/tzlocal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz-deprecation-shim>0:devel/py-pytz-deprecation-shim@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|64|63|g' ${WRKSRC}/pyproject.toml

do-test:
	@cd ${WRKSRC}/test && pytest

.include <bsd.port.mk>
