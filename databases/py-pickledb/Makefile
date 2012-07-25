# New ports collection makefile for: py-pickledb
# Date created:		2011-11-04
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pickleDB
PORTVERSION=	0.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	A lightweight, fast, and simple key-value store

LICENSE=	BSD

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pickledb.py \
		%%PYTHON_SITELIBDIR%%/pickledb.pyc \
		%%PYTHON_SITELIBDIR%%/pickledb.pyo

.include <bsd.port.mk>
