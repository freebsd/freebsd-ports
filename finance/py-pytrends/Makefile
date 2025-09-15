PORTNAME=	pytrends
DISTVERSION=	4.9.2
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pseudo API for Google Trends
WWW=		https://github.com/GeneralMills/pytrends

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.25:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # many tests fail, see https://github.com/GeneralMills/pytrends/issues/608

NO_ARCH=	yes

.include <bsd.port.mk>
