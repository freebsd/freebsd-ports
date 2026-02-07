PORTNAME=	xstatic-objectpath
PORTVERSION=	1.2.1.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-objectpath-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	objectpath (XStatic packaging standard)
WWW=		https://github.com/openstack-archive/deb-python-xstatic-objectpath \
		https://github.com/mike-marcacci/objectpath

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
