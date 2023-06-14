PORTNAME=	pymisp
PORTVERSION=	2.4.162.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python library to access MISP platforms via their REST API
WWW=		https://github.com/MISP/PyMISP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix

SHEBANG_FILES=	pymisp/data/misp-objects/validate_all.sh \
		pymisp/data/misp-objects/jq_all_the_things.sh \
		pymisp/data/misp-objects/tools/validate_opposites.sh

USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		bash>0:shells/bash

NO_ARCH=	yes

.include <bsd.port.mk>
