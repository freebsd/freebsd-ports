# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	hy
PORTVERSION=	0.17.0
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Dialect of Lisp that is embedded in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>=0.8:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clint>=0.4:devel/py-clint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastentrypoints>0:devel/py-fastentrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rply>=0.7.7:devel/py-rply@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
