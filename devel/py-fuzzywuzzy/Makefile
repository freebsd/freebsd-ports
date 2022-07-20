PORTNAME=	fuzzywuzzy
PORTVERSION=	0.18.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Fuzzy string matching using Levenshtein Distance

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-Levenshtein>0:devel/py-python-Levenshtein@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
