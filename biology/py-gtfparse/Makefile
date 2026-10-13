PORTNAME=	gtfparse
DISTVERSION=	3.0.2
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parsing tools for GTF (gene transfer format) files
WWW=		https://github.com/openvax/gtfparse

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=2.2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=18.0.0:databases/py-pyarrow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests from the PYPI tarball fail because 'data' module is missing, and the GH repository doesn't have tags, see https://github.com/openvax/gtfparse/issues/53

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 3.0.2: 213 passed in 2.65s

.include <bsd.port.mk>
