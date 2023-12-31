PORTNAME=	multiset
DISTVERSION=	3.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of a multiset
WWW=		https://github.com/wheerd/multiset

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	pep517 autoplist pytest

DOS2UNIX_FILES=	pyproject.toml

NO_ARCH=	yes

.include <bsd.port.mk>
