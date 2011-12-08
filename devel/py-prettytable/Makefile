# New ports collection makefile for:	py-prettytable
# Date created:				2011-12-08
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prettytable
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/P/PrettyTable
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for displaying tabular data in an ASCII table format

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
