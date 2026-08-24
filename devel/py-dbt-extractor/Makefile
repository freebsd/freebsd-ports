PORTNAME=	dbt-extractor
DISTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dbt_extractor-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	patmaddox@FreeBSD.org
COMMENT=	Analyze and extract information from Jinja used in dbt projects
WWW=		https://github.com/dbt-labs/dbt-extractor/

LICENSE=	APACHE20

BUILD_DEPENDS=	maturin:devel/py-maturin@${PY_FLAVOR} \
		${PY_SETUPTOOLS}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

post-extract:
	${RM} ${WRKSRC}/build.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} PYO3_PYTHON=${PYTHON_CMD} ${CARGO} test)

.include <bsd.port.mk>
