PORTNAME=	cleo
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create beautiful and testable command-line interfaces
WWW=		https://github.com/python-poetry/cleo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.1.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crashtest>=0.4.1<0.5.0:devel/py-crashtest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz2>=2.2.0<3.0.0:devel/py-rapidfuzz2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
