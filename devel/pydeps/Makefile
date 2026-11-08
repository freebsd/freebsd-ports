PORTNAME=	pydeps
DISTVERSION=	3.0.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display Python module dependencies
WWW=		https://github.com/thebjorn/pydeps

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stdlib-list>0:devel/py-stdlib-list@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
