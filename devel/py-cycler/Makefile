PORTNAME=	cycler
PORTVERSION=	0.12.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI/source/C/Cycler
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Composable style cycles
WWW=		https://pypi.org/project/Cycler/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
