PORTNAME=	xstatic-jsencrypt
PORTVERSION=	2.3.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_jsencrypt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSEncrypt ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://opendev.org/openstack/xstatic-jsencrypt \
		https://github.com/openstack/xstatic-jsencrypt

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
