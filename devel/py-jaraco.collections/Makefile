PORTNAME=	jaraco.collections
DISTVERSION=	5.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME:S|.|_|}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python models and classes to supplement the stdlib ‘collections’
WWW=		https://github.com/jaraco/jaraco.collections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.text>=0:devel/py-jaraco.text@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S|.|_|}-${PORTVERSION}

.include <bsd.port.mk>
