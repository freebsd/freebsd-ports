PORTNAME=	awesomeversion
PORTVERSION=	25.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	One version package to rule them all
WWW=		https://github.com/ludeeus/awesomeversion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
