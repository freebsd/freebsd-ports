PORTNAME=	zipkin
PORTVERSION=	1.2.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_zipkin-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Library for using Zipkin in Python
WWW=		https://github.com/Yelp/py_zipkin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
