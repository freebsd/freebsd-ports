# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_activity
PORTVERSION=	1.4.0
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Htop like application for PostgreSQL server activity monitoring

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	julmon

USE_PYTHON=	autoplist distutils noegginfo concurrent optsuffix
PYDISTUTILS_INSTALLARGS=	--with-man

post-patch:
	${REINPLACE_CMD} -e 's|\/usr\/share|${MAN1PREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
