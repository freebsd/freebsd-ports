PORTNAME=	testpath
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Test utilities for Python code working with files and commands 

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0,1:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

do-test:
	cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
