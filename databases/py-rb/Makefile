PORTNAME=	rb
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis blaster
WWW=		https://rb.readthedocs.io/en/latest/ \
		https://github.com/getsentry/rb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis2>=2.6:databases/py-redis2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	getsentry

.include <bsd.port.mk>
