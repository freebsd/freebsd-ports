PORTNAME=	awscli
PORTVERSION=	1.42.29
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Universal Command Line Interface for Amazon Web Services
WWW=		https://aws.amazon.com/cli/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.31.35:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.2:security/py-rsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3transfer>=0.6.0:net/py-s3transfer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
SUB_FILES=	pkg-message

.include <bsd.port.mk>
