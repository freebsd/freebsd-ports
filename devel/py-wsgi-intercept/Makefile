PORTNAME=	wsgi-intercept
PORTVERSION=	1.13.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/cdent/wsgi-intercept/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wsgi_intercept-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WSGI application in place of a real URI for testing
WWW=		https://wsgi-intercept.readthedocs.io/en/latest/ \
		https://github.com/cdent/wsgi-intercept

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
