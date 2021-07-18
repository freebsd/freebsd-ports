PORTNAME=	setuptools_scm
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Setuptools plugin to manage your versions by scm tags

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		git:devel/git \
		${PY_MERCURIAL}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		TOML
OPTIONS_DEFAULT=	TOML

TOML_DESC=		Support for parsing pyproject.toml files [PEP 517/518]
TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
