# $FreeBSD$

PORTNAME=	ttictoc
PORTVERSION=	0.5.6
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Time execution of blocks of code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR}

USES=	localbase python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
