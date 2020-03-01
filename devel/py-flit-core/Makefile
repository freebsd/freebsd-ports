# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flit-core
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flit_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution-building parts of Flit

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytoml>=0:textproc/py-pytoml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>
