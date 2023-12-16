PORTNAME=	thefuzz
PORTVERSION=	0.20.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Fuzzy string matching in Python
WWW=		https://github.com/seatgeek/thefuzz

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rapidfuzz>=0:devel/py-rapidfuzz@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
