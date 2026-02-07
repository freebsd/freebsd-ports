PORTNAME=	inquirer
DISTVERSION=	3.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of common interactive command line user interfaces
WWW=		https://github.com/magmax/python-inquirer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blessed>=1.19.0:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editor>=1.6.0:editors/py-editor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readchar>=4.2.0:textproc/py-readchar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
