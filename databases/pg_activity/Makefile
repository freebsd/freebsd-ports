PORTNAME=	pg_activity
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Htop like application for PostgreSQL server activity monitoring

LICENSE=	PostgreSQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blessed>=0:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${PY_FLAVOR}

USES=		python:3.6+

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	dalibo

USE_PYTHON=	autoplist distutils noegginfo concurrent optsuffix

post-patch:
	${REINPLACE_CMD} -e 's|\/usr\/share|${MAN1PREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
