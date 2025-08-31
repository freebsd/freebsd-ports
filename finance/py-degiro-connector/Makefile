PORTNAME=	degiro-connector
DISTVERSION=	3.0.27
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to access Degiro's API
WWW=		https://github.com/chavithra/degiro-connector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0.6.1:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onetimepass>=1.0.1:www/py-onetimepass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.9.10:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.5:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>=0.20.2:misc/py-polars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.7:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14.1:devel/py-wrapt@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist

#USE_GITHUB=	yes
#GH_ACCOUNT=	chavithra

NO_ARCH=	yes

.include <bsd.port.mk>
