PORTNAME=	wand
PORTVERSION=	0.7.2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI \
		https://github.com/emcconville/wand/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ctypes-based simple MagickWand API binding for Python
WWW=		https://docs.wand-py.org/en/latest/ \
		https://github.com/emcconville/wand

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		magick python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
