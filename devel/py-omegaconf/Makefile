PORTNAME=	omegaconf
DISTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible configuration library
WWW=		https://github.com/omry/omegaconf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${ANTLR_JAR}:devel/antlr4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=4.13:devel/py-antlr4-python3-runtime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}

USES=		java:build python

USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

NO_ARCH=	yes

ANTLR_JAR=	${JAVAJARDIR}/antlr-4.13.2-complete.jar

# tests as of 2.3.1: 10 failed, 7761 passed, 354 skipped, 8 xfailed in 57.22s, failures are because if the missing build_helpers/test_files

# The bundled antlr 4.9.3 generates a parser that the antlr4 runtime in the
# tree refuses to load, so generate it with devel/antlr4 instead
post-patch:
	@${REINPLACE_CMD} -e 's|^\( *\)"java",$$|\1"${JAVA}",|' \
		-e 's|str(build_dir / "bin" / "antlr-4.9.3-complete.jar")|"${ANTLR_JAR}"|' \
		${WRKSRC}/build_helpers/build_helpers.py

.include <bsd.port.mk>
