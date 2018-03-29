# $FreeBSD$

PORTNAME=	clojure_py
PORTVERSION=	0.2.4
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Clojure in Python

LICENSE=	EPL

BROKEN=		does not build with latest setuptools (39.0.1)
DEPRECATED=	Upstream disappeared
EXPIRATION_DATE=2018-04-30

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
