PORTNAME=	cloudpathlib
PORTVERSION=	0.23.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	pathlib-style classes for cloud storage services
WWW=		https://cloudpathlib.drivendata.org/stable/ \
		https://github.com/drivendataorg/cloudpathlib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4.0:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GS S3
GS_DESC=	Google Cloud Storage support
S3_DESC=	Amazon S3 support

GS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=0:www/py-google-cloud-storage@${PY_FLAVOR}
S3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.34.0:www/py-boto3@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
