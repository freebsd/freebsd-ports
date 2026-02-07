PORTNAME=	xstatic-jasmine
PORTVERSION=	2.4.1.2
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Jasmine-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jasmine (XStatic packaging standard)
WWW=		https://jasmine.github.io/ \
		https://github.com/openstack/xstatic-jasmine \
		https://github.com/jasmine/jasmine-py

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
