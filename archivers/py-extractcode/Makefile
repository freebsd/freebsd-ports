PORTNAME=	extractcode
DISTVERSION=	31.0.0
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Universal file extraction library and CLI tool to extract almost any archive
WWW=		https://github.com/aboutcode-org/extractcode

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		libarchive>13:archivers/libarchive
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>18:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}commoncode>=30.2.0:devel/py-commoncode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plugincode>=21.1.21:devel/py-plugincode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typecode>=21.1.21:devel/py-typecode@${PY_FLAVOR} \
		libarchive>13:archivers/libarchive

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
