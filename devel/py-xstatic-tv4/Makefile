PORTNAME=	xstatic-tv4
PORTVERSION=	1.2.7.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-tv4-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	tv4 (XStatic packaging standard)
WWW=		https://geraintluff.github.io/tv4/ \
		https://github.com/openstack-archive/deb-python-xstatic-tv4 \
		https://github.com/geraintluff/tv4

LICENSE=	MIT PD
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
