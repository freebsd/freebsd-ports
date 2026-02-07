PORTNAME=	jsonschema-path
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jsonschema_path-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSONSchema Spec with object-oriented paths
WWW=		https://github.com/p1c2u/jsonschema-path

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pathable>=0.4.1<0.5:devel/py-pathable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}referencing>=0<0.38.0:devel/py-referencing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0<3:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
