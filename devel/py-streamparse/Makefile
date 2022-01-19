# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	streamparse
PORTVERSION=	4.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python analysis of Apache Storm streams

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fabric3>0:devel/py-fabric3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pystorm>=3.1.1:devel/py-pystorm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0:textproc/py-texttable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thriftpy2>=0:devel/py-thriftpy2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>=0:devel/py-unittest2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>=0:graphics/py-graphviz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
