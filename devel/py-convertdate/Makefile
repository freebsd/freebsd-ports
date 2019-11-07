# $FreeBSD$

PORTNAME=	convertdate
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Converts between Gregorian dates and other calendar systems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyephem>0:astro/pyephem@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

NO_ARCH=	yes

post-patch:
	${RM}    ${WRKSRC}/README.rst
	${TOUCH} ${WRKSRC}/README.rst

.include <bsd.port.mk>
