PORTNAME=	gtfparse
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parsing tools for GTF (gene transfer format) files
WWW=		https://github.com/openvax/gtfparse

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>=0.20.2:misc/py-polars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=14.0.2:databases/py-pyarrow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests from the PYPI tarball fail because 'data' module is missing, and the GH repository doesn't have tags, see https://github.com/openvax/gtfparse/issues/53

NO_ARCH=	yes

.include <bsd.port.mk>
