PORTNAME=	xstatic-bootswatch
PORTVERSION=	3.3.7.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-bootswatch-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	bootswatch (themes for Bootstrap) (XStatic packaging standard)
WWW=		https://bootswatch.com/ \
		https://github.com/openstack/xstatic-bootswatch

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
