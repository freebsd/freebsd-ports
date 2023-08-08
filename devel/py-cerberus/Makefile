PORTNAME=	Cerberus
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Lightweight, extensible validation tool for Python dictionaries
WWW=		https://github.com/pyeve/cerberus

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

# benchmark tests are missing files not included in PYPI tarballs and
# break running pytest at all

post-patch:
	${RM} ${WRKSRC}/cerberus/benchmarks/test_overall_performance_1.py
	${RM} ${WRKSRC}/cerberus/benchmarks/test_overall_performance_2.py

# Not to be confused with devel/py-pycerberus which fulfils a quite
# different function.

.include <bsd.port.mk>
