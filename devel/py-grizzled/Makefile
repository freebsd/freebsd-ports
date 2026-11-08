PORTNAME=	grizzled
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The Grizzled Python Utility Library
WWW=		https://github.com/bmc/grizzled-python/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/README.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

SUB_FILES=	pyproject.toml
SUB_LIST=	PORTVERSION=${PORTVERSION}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

pre-configure:
	${MV} ${WRKDIR}/pyproject.toml ${WRKSRC}

.include <bsd.port.mk>
