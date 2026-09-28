PORTNAME=	pytest-randomly
DISTVERSION=	5.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pytest plugin to randomly order tests and control random.seed
WWW=		https://github.com/pytest-dev/pytest-randomly

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.12.1:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=8:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "MIT"|license = { text = "MIT" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
