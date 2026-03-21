PORTNAME=	tox-ini-fmt
PORTVERSION=	1.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	tox_ini_fmt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic virtualenv management and test command line tool
WWW=		https://github.com/tox-dev/tox-ini-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.5:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=25:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
