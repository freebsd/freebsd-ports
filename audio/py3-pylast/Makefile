# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pylast
PORTVERSION=	0.5.11
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Python3 interface to Last.fm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	3
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pylast.py \
		%%PYTHON_SITELIBDIR%%/__pycache__/pylast.cpython-33.pyc \
		%%PYTHON_SITELIBDIR%%/__pycache__/pylast.cpython-33.pyo

.include <bsd.port.mk>
