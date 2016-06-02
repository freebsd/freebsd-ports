# $FreeBSD$

PORTNAME=	tzlocal
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	Returns the tzinfo object for the local timezone

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
