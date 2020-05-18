# $FreeBSD$

PORTNAME=	pymisp
PORTVERSION=	2.4.125
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python library to access MISP platforms via their REST API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	python shebangfix

SHEBANG_FILES=	pymisp/data/misp-objects/validate_all.sh pymisp/data/misp-objects/jq_all_the_things.sh

USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
