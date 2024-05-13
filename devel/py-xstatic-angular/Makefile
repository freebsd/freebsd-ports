PORTNAME=	xstatic-angular
PORTVERSION=	1.8.2.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Angular-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Angular (XStatic packaging standard)
WWW=		https://angularjs.org/ \
		https://github.com/openstack/xstatic-angular

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
