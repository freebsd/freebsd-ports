PORTNAME=	d2to1
DISTVERSION=	0.2.12.post1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Distutils2-like setup.cfg files with setuptools setup.py
WWW=		https://github.com/iguananaut/d2to1

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PY_SETUPTOOLS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

GH_ACCOUNT=	embray

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
