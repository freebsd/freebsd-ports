PORTNAME=	py-partiql-parser
PORTVERSION=	0.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/getmoto/py-partiql-parser/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_partiql_parser-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Python PartiQL Parser
WWW=		https://github.com/getmoto/py-partiql-parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
