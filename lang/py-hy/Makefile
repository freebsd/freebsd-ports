# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	hy
PORTVERSION=	0.13.0
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Hy is a dialect of lisp that's is embedded in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}args>0:devel/py-args \
		${PYTHON_PKGNAMEPREFIX}astor>0:devel/py-astor \
		${PYTHON_PKGNAMEPREFIX}clint>0:devel/py-clint \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}rply>0:devel/py-rply \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
