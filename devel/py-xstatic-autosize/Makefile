PORTNAME=	xstatic-autosize
PORTVERSION=	6.0.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_autosize-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	autosize ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://github.com/xstatic-py/xstatic-autosize

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
