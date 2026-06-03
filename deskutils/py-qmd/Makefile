PORTNAME=	qmd
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	On-device hybrid search engine for Markdown documents
WWW=		https://github.com/chengzhag/qmd-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentence-transformers>=0:misc/py-sentence-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-vec>0:databases/py-sqlite-vec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.41:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

CONFLICTS_INSTALL=	qmd

NO_ARCH=	yes

.include <bsd.port.mk>
