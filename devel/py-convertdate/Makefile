# $FreeBSD$

PORTNAME=	convertdate
PORTVERSION=	2.1.3
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/81/73/287ef9e7989661ed8218fe074603041d2ea6d76e06afebe1c646a7fd9d65/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Converts between Gregorian dates and other calendar systems

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyephem>0:astro/pyephem@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

NO_ARCH=	yes

post-patch:
	${RM}    ${WRKSRC}/README.rst
	${TOUCH} ${WRKSRC}/README.rst

.include <bsd.port.mk>
