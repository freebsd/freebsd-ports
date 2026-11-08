PORTNAME=	optype
PORTVERSION=	0.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Building Blocks for Precise & Flexible Type Hints
WWW=		https://github.com/jorenham/optype/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
