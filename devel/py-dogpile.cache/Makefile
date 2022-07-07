# Created by: William Grzybowski <william88@gmail.com>

PORTNAME=	dogpile.cache
PORTVERSION=	1.1.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Caching front-end based on the Dogpile lock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=4.0.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdbm>=0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.0.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
