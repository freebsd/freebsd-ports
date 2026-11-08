PORTNAME=	omegaconf
DISTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible configuration library
WWW=		https://github.com/hydra-ecosystem/omegaconf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${ANTLR_JAR}:devel/antlr4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1.0:devel/py-pyyaml@${PY_FLAVOR}

USES=		java:build python

USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

NO_ARCH=	yes

ANTLR_JAR=	${JAVAJARDIR}/antlr-4.13.2-complete.jar

# The bundled antlr 4.11.1 generates a parser that we replace with the system antlr4 jar.
post-patch:
	@${REINPLACE_CMD} -e 's|^\( *\)"java",$$|\1"${JAVA}",|' \
		-e 's|str(build_dir / "bin" / "antlr-4.11.1-complete.jar")|"${ANTLR_JAR}"|' \
		${WRKSRC}/build_helpers/build_helpers.py

pre-test: # skip tests requiring unavailable dependencies/network/website
	@${RM} ${WRKSRC}/tests/test_dependency_audit.py
	@${RM} ${WRKSRC}/tests/test_dependency_audit_invariants.py
	@${RM} ${WRKSRC}/tests/test_dependency_audit_pnpm.py
	@${RM} ${WRKSRC}/tests/test_dependency_audit_repairs.py
	@${RM} ${WRKSRC}/tests/test_dependency_audit_workflow.py
	@${RM} ${WRKSRC}/tests/test_website_api_deprecations.py
	@${RM} ${WRKSRC}/tests/test_website_examples.py

# tests as of 2.4.0: 11 failed, 8816 passed, 363 skipped (failures are due to missing build_helpers/test_files and release workflow tests)

.include <bsd.port.mk>
