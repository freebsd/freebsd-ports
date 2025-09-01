PORTNAME=	dbt-extractor
PORTVERSION=	0.5.1
PORTREVISION=	16
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dbt_extractor-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	pat@patmaddox.com
COMMENT=	Analyze and extract information from Jinja used in dbt projects
WWW=		https://github.com/dbt-labs/dbt-extractor/

LICENSE=	APACHE20

BUILD_DEPENDS=	maturin:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>0:devel/py-tree-sitter@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

post-extract:
	${LN} -s ${WRKDIR}/tree-sitter-jinja2-*/ ${WRKSRC}/tree-sitter-dbt-jinja

pre-build:
	cd ${WRKSRC} && maturin build -f
	${MKDIR} ${WRKSRC}/dist
	${CP} ${WRKSRC}/target/wheels/${DISTNAME}-*freebsd*.whl ${WRKSRC}/dist/

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} PYO3_PYTHON=${PYTHON_CMD} ${CARGO} test)

.include <bsd.port.mk>
