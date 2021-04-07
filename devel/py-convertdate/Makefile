PORTNAME=	convertdate
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Converts between Gregorian dates and other calendar systems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=2014.10:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymeeus>=0.3.6,<1:astro/py-pymeeus@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	${RM}    ${WRKSRC}/README.rst
	${TOUCH} ${WRKSRC}/README.rst

.include <bsd.port.mk>
