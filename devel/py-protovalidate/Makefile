PORTNAME=	protovalidate
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffer Validation for Python
WWW=		https://protovalidate.com/ \
		https://github.com/bufbuild/protovalidate-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cel-python>=0.2<0.3:devel/py-cel-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-re2>=1.1.20250722:devel/py-google-re2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
