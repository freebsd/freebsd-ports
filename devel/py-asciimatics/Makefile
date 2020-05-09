# $FreeBSD$

PORTNAME=	asciimatics
PORTVERSION=	1.11.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mouse/keyboard input, text color/positioning, and ASCII animations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyfiglet>=0.7.2:misc/py-pyfiglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>0:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
