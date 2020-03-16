# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib
PORTVERSION=	0.15.19
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python's MediaWiki Parser and Utility Library

LICENSE=	BSD3CLAUSE

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-03-19

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apipkg>=1.2:devel/py-apipkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0.10:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.8:devel/py-lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}odfpy>=0.9:devel/py-odfpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.8:devel/py-lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timelib>=0.2:devel/py-timelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf>=1.12:print/py-pdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow6>0:graphics/py-pillow6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.0:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qserve>=0:devel/py-qserve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}roman>=0:math/py-roman@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>2.0.8:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3dbm>=0:databases/py-sqlite3dbm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timelib>=0.2:devel/py-timelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${PY_FLAVOR}

USES=		python:2.7 shebangfix zip
SHEBANG_FILES=	mwlib/EasyTimeline.pl mwlib/writer/*.py \
		mwlib/refine/*.py mwlib/parser/*.py \
		mwlib/net/*.py mwlib/siteinfo/*.py
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mwqserve nserve nslave postman

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mwlib/_uscan.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mwlib/templ/*.so

.include <bsd.port.mk>
