# New ports collection makefile for:    py-sqlite3dbm
# Date created:				Oct 28, 2011
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3dbm
PORTVERSION=	0.1.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Sqlite-backed dictionary

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_PYTHON=	2.6+
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
