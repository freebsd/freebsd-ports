PORTNAME=	xstatic-angular-bootstrap
PORTVERSION=	2.5.0.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Angular-Bootstrap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Angular-Bootstrap (XStatic packaging standard)
WWW=		https://angular-ui.github.io/bootstrap/ \
		https://github.com/openstack/xstatic-angular-bootstrap

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
