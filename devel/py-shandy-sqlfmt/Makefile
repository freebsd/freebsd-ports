PORTNAME=	shandy-sqlfmt
PORTVERSION=	0.27.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Sqlfmt formats your dbt SQL files so you don't have to
WWW=		https://sqlfmt.com \
		https://github.com/tconbeer/sqlfmt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0<9.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0<4.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.4<5.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0<5.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=   ${PYTHON_PKGNAMEPREFIX}toml>=2.0<3.0:textproc/py-toml@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
