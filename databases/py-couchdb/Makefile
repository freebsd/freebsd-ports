PORTNAME=	CouchDB
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	niwi@niwi.be
COMMENT=	Simple Library to Allow Python Applications to Use CouchDB
WWW=		https://code.google.com/p/couchdb-python/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pythonprefix

.include <bsd.port.mk>
