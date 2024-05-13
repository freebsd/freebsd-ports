PORTNAME=	xstatic-jsencrypt
PORTVERSION=	2.3.1.1
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-JSEncrypt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSEncrypt (XStatic packaging standard)
WWW=		https://travistidwell.com/jsencrypt/ \
		https://github.com/openstack/xstatic-jsencrypt

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
