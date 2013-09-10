# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	importlib
PORTVERSION=	1.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	akosiaris+ports@gmail.com
COMMENT=	Backport of importlib.import_module() from Python 2.7

DEPRECATED=	Python 2.6 port will reach it's EoL upstream soon
EXPIRATION_DATE=2013-10-01

USE_PYTHON=	2.6
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/importlib/__init__.py \
		%%PYTHON_SITELIBDIR%%/importlib/__init__.pyc \
		%%PYTHON_SITELIBDIR%%/importlib/__init__.pyo
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/importlib

.include <bsd.port.mk>
