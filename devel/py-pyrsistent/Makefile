# $FreeBSD$

PORTNAME=	pyrsistent
PORTVERSION=	0.14.11
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Persistent/Functional/Immutable data structures

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.mit

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis<5:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pvectorc.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
