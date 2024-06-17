PORTNAME=	mypy-boto3-s3
DISTVERSION=	1.34.120
CATEGORIES=	devel python
MASTER_SITES=	PYPI # no tests
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Type annotations for boto3.S3 service
WWW=		https://github.com/youtype/mypy_boto3_builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
