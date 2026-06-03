PORTNAME=	session-info2
PORTVERSION=	0.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	session_info2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print versions of imported packages
WWW=		https://session-info2.readthedocs.io/en/stable/ \
		https://github.com/scverse/session-info2

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-docstring-description>=0:devel/py-hatch-docstring-description@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
