PORTNAME=	termcolor
DISTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arcade@b1t.name
COMMENT=	ANSI Color formatting for output in terminal
WWW=		https://pypi.org/project/termcolor/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
