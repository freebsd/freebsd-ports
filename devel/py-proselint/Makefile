PORTNAME=	proselint
DISTVERSION=	0.16.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Linter for prose
WWW=		https://github.com/amperser/proselint

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-re2>=1.1.20251105:devel/py-google-re2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-re2-stubs>=0.1.1:devel/py-google-re2-stubs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|uv_build>=0.7.22,<0.8.0|uv_build>=0.7.22|g' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
