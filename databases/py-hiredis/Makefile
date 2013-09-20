# Created by: Denis Generalov <gd@rambler-co.ru>
# $FreeBSD$

PORTNAME=	hiredis
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gd@rambler-co.ru
COMMENT=	Python extension that wraps hiredis

LICENSE=	BSD

LIB_DEPENDS=	hiredis:${PORTSDIR}/databases/hiredis

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/hiredis/__init__.py \
		%%PYTHON_SITELIBDIR%%/hiredis/__init__.pyc \
		%%PYTHON_SITELIBDIR%%/hiredis/__init__.pyo \
		%%PYTHON_SITELIBDIR%%/hiredis/hiredis.so \
		%%PYTHON_SITELIBDIR%%/hiredis/version.py \
		%%PYTHON_SITELIBDIR%%/hiredis/version.pyc \
		%%PYTHON_SITELIBDIR%%/hiredis/version.pyo
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/hiredis

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
