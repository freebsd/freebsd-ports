PORTNAME=	gizeh
DISTVERSION=	0.1.11
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple vector graphics in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairocffi>0:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
