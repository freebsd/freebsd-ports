PORTNAME=	xstatic-term.js
PORTVERSION=	0.0.7.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-term.js-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	term.js (XStatic packaging standard)
WWW=		https://github.com/openstack-archive/deb-python-xstatic-term.js \
		https://github.com/chjj/term.js

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
