PORTNAME=	xstatic-jquery.quicksearch
PORTVERSION=	2.0.3.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_jquery_quicksearch-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JQuery.quicksearch ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://opendev.org/openstack/xstatic-jquery.quicksearch \
		https://github.com/openstack/xstatic-jquery.quicksearch

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
