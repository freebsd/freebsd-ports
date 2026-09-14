PORTNAME=	types-s3transfer
DISTVERSION=	0.16.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Type annotations and code completion for s3transfer
WWW=		https://github.com/youtype/types-s3transfer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscrt>0:devel/py-awscrt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${PY_FLAVOR} # deps not declared, see https://github.com/youtype/types-s3transfer/issues/4

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
