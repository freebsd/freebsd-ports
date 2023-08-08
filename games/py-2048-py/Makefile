PORTNAME=	2048-py
DISTVERSION=	0.1.6
CATEGORIES=	games python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MASTER_SITES=	PYPI

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Console version of the 2048 game written in Python
WWW=		https://github.com/LadueCS/2048

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
