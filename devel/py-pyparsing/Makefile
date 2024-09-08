PORTNAME=	pyparsing
PORTVERSION=	3.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General parsing module for Python
WWW=		https://pyparsing-docs.readthedocs.io/en/latest/ \
		https://github.com/pyparsing/pyparsing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DIAGRAMS
DIAGRAMS_DESC=	Diagram support

DIAGRAMS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}railroad-diagrams>=0:graphics/py-railroad-diagrams@${PY_FLAVOR}

.include <bsd.port.mk>
