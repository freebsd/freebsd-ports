PORTNAME=	xstatic-rickshaw
PORTVERSION=	1.5.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Rickshaw-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rickshaw (XStatic packaging standard)
WWW=		https://tech.shutterstock.com/rickshaw/ \
		https://github.com/openstack/xstatic-rickshaw \
		https://github.com/shutterstock/rickshaw

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
