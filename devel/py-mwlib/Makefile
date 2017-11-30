# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib
PORTVERSION=	0.15.14
PORTREVISION=	7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python's MediaWiki Parser and Utility Library

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apipkg>=1.2:devel/py-apipkg@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0.10:www/py-bottle@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flup>=1.0:www/py-flup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.8:devel/py-lockfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}odfpy>=0.9:devel/py-odfpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.8:devel/py-lockfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timelib>=0.2:devel/py-timelib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf>=1.12:print/py-pdf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.0:devel/py-py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qserve>=0:devel/py-qserve@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}roman>=0:math/py-roman@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>2.0.8:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3dbm>=0:databases/py-sqlite3dbm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timelib>=0.2:devel/py-timelib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${FLAVOR}

USES=		python:2 shebangfix zip
SHEBANG_FILES=	mwlib/EasyTimeline.pl mwlib/writer/*.py \
		mwlib/refine/*.py mwlib/parser/*.py \
		mwlib/net/*.py mwlib/siteinfo/*.py
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mwqserve nserve nslave postman

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-patch:
	${REINPLACE_CMD} \
		-e 's|lockfile==|lockfile>=|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mwlib/_uscan.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mwlib/templ/*.so

.include <bsd.port.mk>
