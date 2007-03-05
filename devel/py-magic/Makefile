# New ports collection makefile for:	py-magic
# Date created:				19 Nov 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	magic
PORTVERSION=	4.20
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	file-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python module for determing file type

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

WRKSRC=	${WRKDIR}/file-${PORTVERSION}/python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/magic.so

.include <bsd.port.mk>
