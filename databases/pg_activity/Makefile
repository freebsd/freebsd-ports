PORTNAME=	pg_activity
PORTVERSION=	3.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Htop like application for PostgreSQL server activity monitoring
WWW=		https://github.com/dalibo/pg_activity

LICENSE=	PostgreSQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blessed>=0:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=20.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${PY_FLAVOR}

USES=		python

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	dalibo

USE_PYTHON=	autoplist distutils noegginfo concurrent optsuffix

post-patch:
	${REINPLACE_CMD} -e 's|\/usr\/share|${PREFIX}/share|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
