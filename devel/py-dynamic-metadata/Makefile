PORTNAME=	dynamic-metadata
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dynamic_metadata-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Document dynamic-metadata support
WWW=		https://dynamic-metadata.readthedocs.io/en/latest/ \
		https://github.com/scikit-build/dynamic-metadata

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
