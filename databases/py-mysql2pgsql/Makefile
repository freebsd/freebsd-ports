# $FreeBSD$

PORTNAME=	mysql2pgsql
PORTVERSION=	0.1.6
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	postgresql

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Tool for migrating/converting from mysql to postgresql

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>0:${PORTSDIR}/databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:${PORTSDIR}/devel/py-termcolor \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml

USE_GITHUB=	yes
GH_ACCOUNT=	philipsoutham
GH_COMMIT=	250cb1c
GH_PROJECT=	py-${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py_${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
