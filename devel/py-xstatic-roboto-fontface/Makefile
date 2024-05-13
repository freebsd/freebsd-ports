PORTNAME=	xstatic-roboto-fontface
PORTVERSION=	0.5.0.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-roboto-fontface-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	roboto-fontface (XStatic packaging standard)
WWW=		https://github.com/openstack/xstatic-roboto-fontface \
		https://github.com/choffmeister/roboto-fontface-bower

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
