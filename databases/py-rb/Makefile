# Created by: Tom Judge <tj@FreeBSD.org>

PORTNAME=	rb
PORTVERSION=	1.9.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis blaster

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis2>=2.6<3.5:databases/py-redis2@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	getsentry
USE_GITHUB=	yes

.include <bsd.port.mk>
