PORTNAME=	degiro-connector
DISTVERSION=	2.0.22
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to access Degiro's API
WWW=		https://github.com/chavithra/degiro-connector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.49.1:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onetimepass>=1.0.1:www/py-onetimepass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.5:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.7:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.12.1:devel/py-wrapt@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

#USE_GITHUB=	yes
#GH_ACCOUNT=	chavithra

NO_ARCH=	yes

.include <bsd.port.mk>
