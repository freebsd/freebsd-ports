PORTNAME=	xstatic-bootstrap-scss
PORTVERSION=	3.4.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Bootstrap-SCSS-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bootstrap-SCSS (XStatic packaging standard)
WWW=		https://github.com/openstack/xstatic-bootstrap-scss \
		https://github.com/twbs/bootstrap-sass

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
