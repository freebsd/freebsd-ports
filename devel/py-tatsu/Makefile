PORTNAME=	tatsu
PORTVERSION=	5.20.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Input a grammar in a variation of EBNF and output a memoizing PEG/Packrat parser in Python
WWW=		https://tatsu.readthedocs.io/en/stable/ \
		https://github.com/neogeny/TatSu

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_GLOB=	*.py

.include <bsd.port.mk>
