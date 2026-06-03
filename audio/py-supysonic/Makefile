PORTNAME=	supysonic
DISTVERSION=	0.7.9
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Python implementation of the Subsonic server API
WWW=		https://supysonic.readthedocs.io/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mediafile>0:devel/py-mediafile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>0:databases/py-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>0:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipstream-ng>0:archivers/py-zipstream-ng@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_RC_SUBR=	supysonic \
		supysonic-daemon

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		USER=supysonic \
		GROUP=supysonic

USERS=		supysonic
GROUPS=		supysonic

PLIST_SUB=	GROUP=supysonic \
		USER=supysonic

OPTIONS_DEFINE=		PGSQL SQLITE3
OPTIONS_DEFAULT=	GUNICORN SQLITE3 PGSQL MYSQLCLIENT
OPTIONS_MULTI=		WSGI
OPTIONS_MULTI_WSGI=	GEVENT GUNICORN WAITRESS
OPTIONS_RADIO=		MYSQL
OPTIONS_RADIO_MYSQL=	MYSQLCLIENT PYMYSQL

GEVENT_DESC=		Install with gevent
GUNICORN_DESC=		Install with gunicorn
MYSQLCLIENT_DESC=	Install with MySQLdb
PYMYSQL_DESC=		Install with pymysql
WAITRESS_DESC=		Install with waitress

GEVENT_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent
GUNICORN_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn
MYSQLCLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
PYMYSQL_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}
SQLITE3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
WAITRESS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}waitress>0:www/py-waitress

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/supysonic.conf ${STAGEDIR}${ETCDIR}/supysonic.conf.sample
.for dir in cache log run
	@${MKDIR} ${STAGEDIR}/var/${dir}/supysonic
.endfor

.include <bsd.port.mk>
