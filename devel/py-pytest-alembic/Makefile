PORTNAME=	pytest-alembic
PORTVERSION=	0.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_alembic-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pytest plugin for verifying alembic migrations
WWW=		https://pytest-alembic.readthedocs.io/en/latest/ \
		https://github.com/schireson/pytest-alembic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=1.9:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.0,1:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

OPTIONS_RADIO=	SQL
OPTIONS_RADIO_SQL=	ALCHEMY14 ALCHEMY20
OPTIONS_DEFAULT=ALCHEMY20
ALCHEMY14_DESC=	Support SQL databases via databases/py-sqlalchemy14
ALCHEMY20_DESC=	Support SQL databases via databases/py-sqlalchemy20

ALCHEMY14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4:databases/py-sqlalchemy14@${PY_FLAVOR}
ALCHEMY20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR}

.include <bsd.port.mk>
