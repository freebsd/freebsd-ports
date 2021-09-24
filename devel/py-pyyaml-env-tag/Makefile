PORTNAME=	pyyaml-env-tag
DISTVERSION=	0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyyaml_env_tag-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Custom YAML tag for referencing environment variables in YAML files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test_yaml_env_tag.py -v

.include <bsd.port.mk>
