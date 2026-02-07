PORTNAME=	xstatic-spin
PORTVERSION=	1.2.5.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Spin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Spin (XStatic packaging standard)
WWW=		https://spin.js.org/ \
		https://github.com/openstack/xstatic-spin \
		https://github.com/fgnass/spin.js

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
