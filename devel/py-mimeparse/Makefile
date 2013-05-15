# New ports collection makefile for:	py-mimeparse
# Date created:				08 May 2012
# Whom:					William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	mimeparse
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Basic functions for handling mime-types in Python

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
