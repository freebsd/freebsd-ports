PORTNAME=	glom
PORTVERSION=	23.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declarative object transformer and formatter
WWW=		https://glom.readthedocs.io/en/latest/ \
		https://github.com/mahmoud/glom

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boltons>=19.3.0:devel/py-boltons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}face>=20.1.0:devel/py-face@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	TOML
OPTIONS_DEFAULT=TOML
TOML_DESC=	TOML (Tom's Obvious Minimal Language) support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOML} && ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
