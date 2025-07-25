PORTNAME=	legacy-api-wrap
PORTVERSION=	1.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	legacy_api_wrap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrap legacy APIs in python projects
WWW=		https://github.com/flying-sheep/legacy-api-wrap

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-docstring-description>=0:devel/py-hatch-docstring-description@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
