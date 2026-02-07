PORTNAME=	multipart
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/defnull/multipart/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser for multipart/form-data
WWW=		https://multipart.readthedocs.io/en/latest/ \
		https://github.com/defnull/multipart

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.9<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
