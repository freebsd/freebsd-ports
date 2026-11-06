PORTNAME=	rubymarshal
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Read and write Ruby-marshalled data
WWW=		https://pypi.org/project/rubymarshal/

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes  # tests are missing from PyPI distribution
GH_ACCOUNT=	d9pouces
GH_PROJECT=	RubyMarshal

USE_PYTHON=	autoplist concurrent pep517 pytest
NO_ARCH=	yes

# the 1.2.10 tag still says 1.2.9; use PORTVERSION so the metadata is right
# and the pep517 wheel matches
post-patch:
	@${REINPLACE_CMD} -e 's|^__version__ = "1.2.9"$$|__version__ = "${PORTVERSION}"|' \
		${WRKSRC}/rubymarshal/__init__.py

.include <bsd.port.mk>
