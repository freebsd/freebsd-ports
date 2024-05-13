PORTNAME=	xstatic-jquery
PORTVERSION=	3.5.1.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-jQuery-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jQuery (XStatic packaging standard)
WWW=		https://jquery.com/ \
		https://github.com/xstatic-py/xstatic-jquery

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
