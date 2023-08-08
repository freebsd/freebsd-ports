PORTNAME=	rb
PORTVERSION=	1.10.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis blaster
WWW=		https://github.com/getsentry/rb

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis2>=2.6:databases/py-redis2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	getsentry
USE_GITHUB=	yes

.include <bsd.port.mk>
