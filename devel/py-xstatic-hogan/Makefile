PORTNAME=	xstatic-hogan
PORTVERSION=	2.0.0.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Hogan-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hogan (XStatic packaging standard)
WWW=		https://twitter.github.io/hogan.js/ \
		https://github.com/openstack/xstatic-hogan \
		https://github.com/twitter/hogan.js

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
